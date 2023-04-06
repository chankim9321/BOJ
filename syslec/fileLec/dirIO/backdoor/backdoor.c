#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	char exec[100];
	setuid(0);
	setgid(0);
	sprintf(exec, "%s 2>/dev/null ", argv[1]);
	system(exec);
	printf("123");
}
