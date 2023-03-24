#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	char* fname = argv[1];
	int fd;
	int fsize;
	off_t offset = 10000;
	char data[] = "\0";
	if((fd = open(fname, O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0){
		perror("open");
		exit(1);
	}

	if((fsize = lseek(fd, offset - 1, SEEK_SET)) < 0){
		perror("lseek");
	}
	write(fd, data, 1);

	close(fd);
	return 0;
}
