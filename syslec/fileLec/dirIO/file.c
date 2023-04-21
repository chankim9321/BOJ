#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char* filename = argv[1];
	struct stat buf;
	if(lstat(filename, &buf) < 0){
		perror("stat error");
		exit(1);
	}

	printf("Mode = %o\n", (unsigned int)buf.st_mode);
	if(S_ISLNK(buf.st_mode)) printf("%s : symbolic\n", filename);
	if(S_ISDIR(buf.st_mode)) printf("%s : Directory\n", filename);
	if(S_ISREG(buf.st_mode)) printf("%s : Regular \n", filename);
	return 0;
}
