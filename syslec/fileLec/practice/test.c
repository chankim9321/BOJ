#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 20

int main(int argc, char *argv[]){
	int fd1, fd2; // 읽을 파일과 쓰기 파일
	char* readFilePath = argv[1];
	char* writeFilePath = argv[2];
	char buf[BUF_SIZE];
	if((fd1 = open(readFilePath, O_RDONLY)) < 0){
		perror("readfile open error");
		exit(1);
	}
	if((fd2 = open(writeFilePath, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0){
		perror("writefile open error");
		exit(1);
	}
	printf("copy start\n");
	// read의 반환값 0은 EOF, -1은 에러
	int readRes;
	while((readRes = read(fd1, buf, BUF_SIZE-1)) > 0){
		buf[readRes]='\0';
		write(fd2, buf, strlen(buf));
	}
	printf("copy done\n");
	
	close(fd1);
	close(fd2);
}
