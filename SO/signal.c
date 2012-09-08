#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void skill (int signum) {

	kill(getpid(),SIGKILL);
}

int main (int argc,char** argv) {
	
	signal(SIGALRM,skill);
	alarm(atoi(argv[1]));
	
	while(1);

	return 0;
}
