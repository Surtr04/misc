#include <unistd.h>
#include <string.h>

int main (int argc, char **argv) {

	int fds[2];
	pipe(fds);
	
	pid_t pid = fork();

	if(pid == 0) {
		close(fds[1]);
		dup2(fds[0],0);

		execlp(argv[1],argv[1],NULL);
	}
	else {
		pid = fork();

		if(pid == 0) {
			close(fds[0]);
			dup2(fds[1],1);
			execlp(argv[2],argv[2],NULL);
		}
		
		close(fds[0]);
		close(fds[1]);
	}

	wait();

}
