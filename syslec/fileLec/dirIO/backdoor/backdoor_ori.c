#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[]){
	char exec[100];
	setuid(0);
	setgid(0);

	sprintf(exec, "%s 2>/dev/null", argv[1]);
	system(exec);
	return 0;
}
