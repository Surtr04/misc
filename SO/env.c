#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

extern char **environ;
char* s = getenv("USER");
printf("%s\n",s);

}
