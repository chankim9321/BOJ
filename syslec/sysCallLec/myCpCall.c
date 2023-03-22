#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 10

int main(int argc, char* argv[]){
	int fd1, fd2, count;
	char buf[MAX_BUF];

	if(argc != 3){
		printf("Usage: %s source destination\n", argv[0]);
		exit(1);		
	}
	if((fd1 = open(argv[1], O_RDONLY)) < 0){ // 읽을 파일
		perror("open");
		exit(1);
	}
	if((fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644)) < 0){ // 복사될 파일
		perror("open");
		exit(1);
	}
	printf("Reading and writing..\n");
	while(read(fd1, buf, strlen(buf)) > 0){
		write(fd2, buf, strlen(buf));
	}
	printf("Copy Done!\n");

	close(fd1);
	close(fd2);

	return 0;
}
