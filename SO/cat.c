#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main (int argc, char **argv) {

	char buffer[1024];
	int i;
	int fd;
	int bytesRead;

	for(i = 1; i < argc; i++) {
		
		fd = open(argv[i],O_RDONLY);
		
		if(fd == -1) {
			perror("error");
			exit(-1);
		}

		while(bytesRead = read(fd,buffer,1024))
			write(1,buffer,bytesRead);	
		
		close(fd);
	}
	

}
