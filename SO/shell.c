#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wordexp.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

typedef struct job {
	int id;
	char *comm;
	pid_t pid;
	struct job *next;
}JobList;

JobList *jobs = NULL;
char* actual_command;
pid_t actual_pid = 0;

int appendJob (char* comm,pid_t pid ) {

	if(jobs == NULL) {
		jobs = (JobList*) malloc (sizeof(JobList));
		jobs->id = 1;
		jobs->comm = strdup(comm);
		jobs->pid = pid;
		jobs->next = NULL;
	}
	else{
		JobList *head = jobs;
		JobList *prev = jobs;
		jobs = jobs->next;

		while(jobs != NULL) {
			jobs = jobs->next;
			prev = prev->next;
		}

		jobs = (JobList*) malloc (sizeof(JobList));
		jobs->id = prev->id + 1;
		jobs->comm = strdup(comm);
		jobs->pid = pid;
		jobs = head;
	}
		
		return 0;
}

JobList* getJob (int id) {

	JobList *head = jobs;
	JobList *target;
	int found = 0;

	while(jobs != NULL && !found) {
		if(jobs->id == id) {
			target = jobs;
			found = 1;
		}	
		jobs = jobs->next;	
	}
	jobs = head;
	if(found)
		return target;
	
	return NULL;
}

JobList* findJob (pid_t pid) {

	JobList *head = jobs;
	JobList *target;
	int found = 0;

	while(jobs != NULL && !found) {
		if(jobs->pid == pid) {
			target = jobs;
			found = 1;
		}	
		jobs = jobs->next;	
	}
	jobs = head;
	if(found)
		return target;
	
	return NULL;
}


void remove_job (pid_t pid) {

	JobList *head = jobs;
	JobList *prev = jobs;
	int found = 0;

	while(jobs && !found) {
		if(jobs->pid == pid) {
			prev->next = jobs->next;
			free(jobs);
			found = 1;
		}
		jobs = jobs->next;
	}

	jobs = head;

}

void printJobs() {

	JobList *head = jobs;

	printf("ID\tPID\tCommand\n");

	while(jobs) {
		printf("%d\t%d\t%s",jobs->id,jobs->pid,jobs->comm);
		jobs = jobs->next;
	}

	jobs = head;
}


int run (char **args,int bg, char *comm,char *in, char *out) {

	pid_t pid = fork();
	int status;

	if(in)
		redir_input(in);
	if(out)
		redir_output(out);

	if(pid == 0) {
		if(bg)
			raise(SIGSTOP);

		execvp(args[0],args);
		perror(args[0]);
		exit(-1);
	}
	else {
		if(bg) {
			appendJob(comm,pid);
		}
		else {
			actual_pid = pid;
			waitpid(pid,&status,0);
			actual_pid = -1;
			if(WIFEXITED(status)) 
			return WEXITSTATUS(status);
		else
			return -1;
		}
	}
}

char** readArgs (char *s,char** in,char**out) {

	static int used = 0;
	static wordexp_t words;

	if (!s) {
		wordfree(&words);
		used = 0;
	}

	if(!used) {
		wordexp(s,&words,0);
		used = 1;
	}
	else {
		wordexp(s,&words,WRDE_REUSE);
		used = 1;
	}

	int i;

	for(i = 0; i < words.we_wordc; i++) {
		if(strcmp(words.we_wordv[i],">") == 0) {
			*out = words.we_wordv[i+1];
			words.we_wordv[i] = NULL;
		}


	}
	
	return words.we_wordv;
}

char* cat (char *str1, char *str2) {

	int size1 = strlen(str1);
	int size2 = strlen(str2);
	char *res = (char*) malloc ((size1 + size2) * sizeof(char));

	memcpy(res,str1,sizeof(char)*size1);
	memcpy(res+(size1),str2,sizeof(char)*size2);

	return res;

}

char *readInput(int *bg) {
	
	char* user = getenv("USER");
	char* prompt = cat(user," > ");
	char* stream = readline(prompt);
	int len = strlen(prompt);
	
	add_history(stream);
	
	*bg = prompt[len-1] == '&';
	if(*bg)
		prompt[len-1] = '\0';

	return stream;
}


int redir_input(const char* file) {

	int fd;

	fd = open(file,O_RDONLY);

	if(dup2(fd,0) == -1)  {//stdin
		return -1;	
	}
	if(close(fd) == -1)
		return -1;

}

int redir_output (const char* file) {

	int fd;

	fd = creat(file,0644);

	if(dup2(fd,1) == -1) //stdout
		return -1;
	if(close(fd) == -1)
		return -1;
}

void killChild(int signum) {

	if (actual_pid != -1) 
		kill(actual_pid,signum);
}

void children (int signum) {
	
	int status;
	pid_t pid = waitpid(-1,&status,WUNTRACED);
	int exited = WIFEXITED(status);
	int stopped = WIFSTOPPED(status);

	JobList *j = findJob(pid);

	if(!j)
		return;

	if(exited) {
		remove_job(pid);
		printf("Job [%d] %s terminated\n", j->id, j->comm);
	}
	else
		if(stopped) {
			printf("Job [%d] %s stopped\n", j->id, j->comm);
		}


}

void stop(int signum) {

	if(actual_pid != -1) {
		kill(actual_pid,signum);
		appendJob(actual_command,actual_pid);
	}

}

int main () {

	signal(SIGINT,killChild);
	signal(SIGSTOP,stop);
	signal(SIGCHLD,children);
	int bg;
	char *in,*out;
	in = out = NULL;

	char *exec = readInput(&bg);
	char *command;

	while(strcmp(exec,"exit") != 0) {
		char **args = readArgs(exec,&in,&out);
		if(strcmp(args[0],"cd") == 0) {
			chdir(args[1]);
		}
		command = exec;
		run(args,bg,command,in,out);
		free(exec);
		exec = readInput(&bg);
	}

}
