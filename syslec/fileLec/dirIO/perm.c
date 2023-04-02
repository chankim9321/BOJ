#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char* filename = argv[1];
	struct stat buf;
	stat(filename, &buf);	
	if((buf.st_mode & 00100) != 0){
		printf("%s : user has a execution permission\n", filename);
	}
	if((buf.st_mode & (00100 >> 3)) != 0){
		printf("%s : group has a execution permission\n", filename);
	}
	if((buf.st_mode & (00100 >> 3)) != 0){
		printf("%s : other has a execution permission\n", filename);
	}
	return 0;
}
