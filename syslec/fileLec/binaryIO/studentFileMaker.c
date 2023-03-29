#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	char name[30];
	int grade[4];
};

int main(int argc, char* argv[]){
	FILE *wfp;
	// data
	struct student p[4] = {
		{"kim",{10,20,30,40}},
		{"lee",{20,30,40,50}},
		{"song",{30,40,50,60}},
		{"park",{100,100,100,100}}
	};

	// 파일 오픈
	if((wfp = fopen("studentInfo.bin", "wb")) == NULL){
		perror("fopne : studentInfo.bin");
		exit(1);
	}
	// 파일 쓰기
	fwrite(p, sizeof(struct student), 4, wfp);
	fclose(wfp);

}
		
