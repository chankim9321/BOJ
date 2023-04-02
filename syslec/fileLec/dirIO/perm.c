#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char* filename = argv[1];
	struct stat buf;
	stat(filename, &buf);	
	printf("------------ Read permission ----------\n");
	if((buf.st_mode & 00400) != 0){
		printf("%s : user has a read permission\n", filename);
	}
	if((buf.st_mode & (00400 >> 3)) != 0){
		printf("%s : group has a read permission\n", filename);
	}
	if((buf.st_mode & (00400 >> 3)) != 0){
		printf("%s : other has a read permission\n", filename);
	}
	printf("------------ Write permission ----------\n");
	if((buf.st_mode & 00200) != 0){
		printf("%s : user has a write permission\n", filename);
	}
	if((buf.st_mode & (00200 >> 3)) != 0){
		printf("%s : group has a write permission\n", filename);
	}
	if((buf.st_mode & (00200 >> 3)) != 0){
		printf("%s : other has a write permission\n", filename);
	}
	printf("------------ Excecution permission ----------\n");
	if((buf.st_mode & 00100) != 0){
		printf("%s : user has a excecution permission\n", filename);
	}
	if((buf.st_mode & (00100 >> 3)) != 0){
		printf("%s : group has a excecution permission\n", filename);
	}
	if((buf.st_mode & (00100 >> 3)) != 0){
		printf("%s : other has a excecution permission\n", filename);
	}
	return 0;
}
