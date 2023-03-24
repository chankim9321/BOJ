#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	off_t fsize;
	int fd;
	char* fname = argv[1];

	if((fd = open(fname, O_RDONLY)) < 0){
		fprintf(stderr, "open error!\n");
		exit(1);
	}
	if((fsize = lseek(fd, 0, SEEK_END)) < 0){
		fprintf(stderr, "lseek error!\n");
		exit(1);
	}

	printf("%s size is = %lld bytes.\n", fname, fsize);
	close(fd);
	return 0;
}
