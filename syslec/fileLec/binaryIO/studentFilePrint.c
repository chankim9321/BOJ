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
	struct student info[5];	

	FILE* rfp;
	int s1, s2, s3, s4;
	int n;
	char* filePath = argv[1]; // 바이너리 파일
	if((rfp = fopen(filePath, "rb")) == NULL){
		perror("fopne : couldn't find file.");
		exit(1);
	}
	struct student s[4];
	// 파일을 읽어서 s[4]에 읽는다
	if(fread(s, sizeof(struct student), 4, rfp) != 4){
		perror("fread : can't read file.");
		exit(1);
	}
	// s[4] 출력 
	for(int i=0; i<4; i++){
		printf("%s : ",s[i].name);
		for(int j=0; j<4; j++){
			printf("%d ",s[i].grade[j]);
		}
		printf("\n");
	}
	fclose(rfp);
}
