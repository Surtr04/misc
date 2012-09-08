#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char **argv) {

	int fd = open(argv[1],O_RDONLY);
	char buffer[128];

	int count = read(fd,buffer,128);
	int i;
	for(i = 0; i < count; i++) {
		if(buffer[i] == '\n' && buffer[i+1] == '\n')
			buffer[i+1] = 'A';

	}
	write(1,buffer,128);



}
