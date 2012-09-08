#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {

	int i,j;
	int fd;
	char buffer[32];
	int bytesRead;
	int bytesWritten;
	char line[16];
	int lineCount = 0;
	char newline = '\n';
	char *ptr;

	for(i = 1; i < argc; i++) {
		
		fd = open (argv[i],O_RDONLY);
		
		if(fd == -1) {
			perror("error");
			exit(-1);
		}

		while(bytesRead = read(fd,buffer,32)) {	

			ptr = buffer;

			for (j = 0; j < bytesRead; j++) {
				if(newline == '\n' && *ptr != '\n') {		
					lineCount++;		
					sprintf(line,"\t%d ",lineCount);
					write(1,line,strlen(line));
				}
				newline = *ptr;
				write(1,ptr++,1);
			}
		}

		close(fd);

	}

}
