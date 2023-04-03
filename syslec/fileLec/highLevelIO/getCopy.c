#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	FILE *fp1; // 복사할 파일
	FILE *fp2; // 생성될 파일
	char* path = argv[1]; // 복사할 파일 경로
	char* fname = argv[2]; // 생성될 파일 이름

	if((fp1 = fopen(path, "rt")) == NULL){
		printf("File1 open error\n");
		exit(1);
	}
	if((fp2 = fopen(fname, "wt")) == NULL){
		printf("File2 open error\n");
		exit(1);
	}
	int data, result;
	while((data = getc(fp1)) != EOF){
		result = putc(data, fp2);
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}