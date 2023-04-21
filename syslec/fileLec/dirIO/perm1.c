#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char* filename = argv[1];
	struct stat buf;
	stat(filename, &buf);	
	printf("------------ Read permission ----------\n");
	if((buf.st_mode & S_IRUSR) != 0){
		printf("%s : user has a read permission\n", filename);
	}
	if((buf.st_mode & S_IRGRP) != 0){
		printf("%s : group has a read permission\n", filename);
	}
	if((buf.st_mode & S_IROTH) != 0){
		printf("%s : other has a read permission\n", filename);
	}
	printf("------------ Write permission ----------\n");
	if((buf.st_mode & S_IWUSR) != 0){
		printf("%s : user has a write permission\n", filename);
	}
	if((buf.st_mode & S_IWGRP) != 0){
		printf("%s : group has a write permission\n", filename);
	}
	if((buf.st_mode & S_IWOTH) != 0){
		printf("%s : other has a write permission\n", filename);
	}
	printf("------------ Excecution permission ----------\n");
	if((buf.st_mode & S_IXUSR) != 0){
		printf("%s : user has a excecution permission\n", filename);
	}
	if((buf.st_mode & S_IXGRP) != 0){
		printf("%s : group has a excecution permission\n", filename);
	}
	if((buf.st_mode & S_IXOTH) != 0){
		printf("%s : other has a excecution permission\n", filename);
	}
	return 0;
}
