#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	char* filename = argv[1];
	char* destname = argv[2];
	int fd1, fd2;
	caddr_t addr1, addr2;
	struct stat buf;
	int pagesize = sysconf(_SC_PAGESIZE);
	int length = pagesize * 1;
	printf("pageSize = %d\n", pagesize * 1); // 페이지사이즈

	off_t offset = 0;

	if(argc != 3){
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}
	// 파일 오픈
	if((fd1 = open(filename, O_RDWR)) == -1){ // 복사할 파일
		perror("fd1 open");
		exit(1);
	}		
	if((fd2 = open(destname, O_RDWR|O_CREAT|O_TRUNC, 0666)) < 0){ // 생성될 파일
		perror("fd2 open");
		exit(1);
	}
	// 파일 사이즈
	if(fstat(fd1, &buf) < 0){
		perror("fstat");
		exit(1);
	}
	if(ftruncate(fd2, buf.st_size) != 0){
		perror("ftruncate");
		exit(1);
	}
	int cycle = 0;
	do{
		if((buf.st_size - offset) < length){
			length = buf.st_size - offset;
		}
		addr1 = mmap(0, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, offset); // 메모리 매핑
		if(addr1 == MAP_FAILED){
			perror("mmap addr1");
			exit(1);
		}
		addr2 = mmap(0, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, offset); // 메모리 매핑
		if(addr2 == MAP_FAILED){
			perror("mmap addr2");
			exit(1);
		}
		memcpy(addr2, addr1, length); // 메모리 복사
		offset += length; // 오프셋 증가
		if(munmap(addr1, length) < 0){ // 매핑 해제
			perror("munmap");
			exit(1);
		}
		if(munmap(addr2, length) < 0){ // 매핑 해제
			perror("munmap");
			exit(1);
		}
		cycle++;
	}while(offset < buf.st_size);
	printf("파일을 쓰는데 호출한 mmap 횟수 = %d\n", cycle);
	close(fd1);
	close(fd2);
}
