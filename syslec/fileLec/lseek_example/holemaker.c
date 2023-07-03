#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int fd;
    off_t pos;

	if(argc != 2){
		fprintf(stderr, "argc required 2 \n");
		exit(1);
	}
	int size = atoi(argv[1]);
    // 파일 디스크립터 열기
    fd = open("holefile", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // 파일 크기 설정
    if (lseek(fd, size, SEEK_SET) == -1) {
        perror("lseek");
        exit(1);
    }

    // 파일 포인터 이동
    pos = lseek(fd, 0, SEEK_CUR);
    if (pos == -1) {
        perror("lseek");
        exit(1);
    }

    // 데이터 쓰기
    if (write(fd, "test", 4) == -1) {
        perror("write");
        exit(1);
    }

    // 파일 디스크립터 닫기
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    return 0;
}

