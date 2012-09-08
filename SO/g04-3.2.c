#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char **argv) {


int matrix[20][20];
	int i,j;
	pid_t pid;
	int search = atoi(argv[1]);
	pid_t pids[20];
	int total = 0;

	for(i = 0; i < 20; i++)
		for(j = 0; j < 20; j++) 
			matrix[i][j] = (rand()*100) % 100;
	
	for(i = 0; i < 20; i++) {

		pid = fork();

		if(pid == 0) {
			for(j = 0; j < 20; j++) {
				if(matrix[i][j] == search)
					total++;
			}
			exit(total);
		}
		else {
			pids[i] = pid;	
		}

	}


	total = 0;
	int status,exitcode;

	for(i = 0; i < 20; i++) {
		waitpid(pids[i],&status,0);
		if(WIFEXITED(status)) {
			exitcode = WEXITSTATUS(status);
			printf("\tLinha %d: Ocorrencias: %d\n",i,exitcode);
			total += exitcode;
		}
	}

	printf("\tTotal de ocorrencias: %d\n",total);

}
