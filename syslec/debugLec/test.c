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
	char* writor;

	for(int i=1; i<argc; i++){
		printf("argv[%d] = %s \n",i,argv[i]);
	}
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
	printf("fd1 = %d\n",fd1);
	printf("fd2 = %d\n",fd2);
	printf("starting..\n");
	while(read(fd1, buf, sizeof(buf)) > 0){
		printf("reading.. and writing..\n");
		write(fd2, buf, strlen(buf));
	}
	printf("end!\n");

	close(fd1);
	close(fd2);

	return 0;
}