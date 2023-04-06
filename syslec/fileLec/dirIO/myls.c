#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	DIR* dp;
	struct dirent* dent;
	if((dp = opendir(argv[1])) == NULL){
		perror("opendir error");
		exit(1);
	}
	while((dent = readdir(dp))){
		char* filename = dent->d_name;
		struct stat buf;
		stat(filename, &buf);
		printf("name = %s\n", filename);
		printf("Inode = %d\n",(int)buf.st_ino);	
		printf("Mode = %d\n", (int)buf.st_mode);
		printf("UID = %d\n", (int)buf.st_uid);
		printf("GID = %d\n", (int)buf.st_gid);
		printf("SIZE = %d\n", (int)buf.st_size);
		printf("------------------------------\n");
	}
	closedir(dp);
}

