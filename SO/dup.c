#include <unistd.h>
#include <wordexp.h>

int main (int argc,char **argv) {

	int fd = creat("cenasDup.txt",0644);

	dup2(fd,1);
	close(fd);
	
	execvp(argv[1],argv+1);

	return 0;
}
