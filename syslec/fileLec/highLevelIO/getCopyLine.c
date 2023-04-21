#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 10

int main(int argc, char* argv[]){
	FILE *fp1; // 복사할 파일
	FILE *fp2; // 생성될 파일
	char* path = argv[1]; // 복사할 파일 경로
	char* fname = argv[2]; // 생성될 파일 이름
	char buf[BUF_SIZE];

	if((fp1 = fopen(path, "rt")) == NULL){
		printf("File1 open error\n");
		exit(1);
	}
	if((fp2 = fopen(fname, "wt")) == NULL){
		printf("File2 open error\n");
		exit(1);
	}
	int data, result;
	char* ptr; // 버퍼를 가르킬 포인터
	while((ptr = fgets(buf, BUF_SIZE, fp1)) != NULL){ // 복사할 파일을 라인단위로 읽어서 버퍼에 저장
		if((result = fputs(ptr, fp2)) == EOF){ // 버퍼의 내용을 생성될 파일에 쓴다
			printf("fputs EOF! or Error!\n");
			exit(1);
		}
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}
