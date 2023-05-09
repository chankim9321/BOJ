#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	char* filename = argv[1];
	char* destname = argv[2];
	int fd, fd2;
	int pid;
	caddr_t addr;
	struct stat buf;
	int pagesize = sysconf(_SC_PAGESIZE);
	int length = pagesize * 1;
	printf("pageSize = %d\n", pagesize * 1);

	off_t offset = 0;
	if(argc != 3){
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}
	if((fd = open(filename, O_RDWR)) == -1){
		perror("fd open");
		exit(1);
	}		
	if((fd2 = open(destname, O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0){
		perror("fd2 open");
		exit(1);
	}
	if(fstat(fd, &buf) < 0){
		perror("fstat");
		exit(1);
	}
	int cycle = 0;
	do{
		if((buf.st_size - offset) < length){
			length = buf.st_size - offset;
		}
		addr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, offset); // 메모리 매핑
		if(addr == MAP_FAILED){
			perror("mmap");
			exit(1);
		}
		write(fd2, addr, length); // 파일에 쓰기
		offset += length; // 오프셋 증가
		if(munmap(addr, length) < 0){ // 매핑 해제
			perror("munmap");
			exit(1);
		}
		cycle++;

	}while(offset < buf.st_size);
	
	printf("파일을 읽는데 호출한 mmap 횟수 = %d\n", cycle);
	close(fd);
	close(fd2);
}
