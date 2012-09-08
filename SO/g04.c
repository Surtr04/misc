#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void find (int* matLine, int line, int num) {

	int i;

	for(i = 0; i < 20; i++) {
		if(matLine[i] == num)
			printf("%d encontrado na linha %d, coluna %d\n",num,line,i);
	}

}

		
int main (int argc, char **argv) {


	int matrix[20][20];
	int i,j;
	pid_t pid;

	for(i = 0; i < 20; i++)
		for(j = 0; j < 20; j++) 
			matrix[i][j] = (rand()*100) % 100;
	for(i = 0; i < 20; i++) {	
		pid = fork();
		if(pid == 0) {
			find(matrix[i],i,atoi(argv[1]));
			exit(0);
		}
	}
	

	return 0;

}
