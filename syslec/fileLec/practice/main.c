#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	char* filepath = argv[1];
	FILE* fwp;
	// 경로에 있는 파일의 정보를 buf에 담는다
	struct stat buf;
	if(stat(filepath, &buf)){
		perror("stat");
		exit(1);
	}
	// filestat.dat 파일에 쓴다
	char filename[50] ="";
	strcat(filename, argv[1]);
	strcat(filename, ".dat");
	if(!(fwp = fopen(filename, "wb"))){
		perror("fopen");
		exit(1);
	}
	fwrite(&buf, sizeof(struct stat), 1, fwp);
	fclose(fwp);	
}
