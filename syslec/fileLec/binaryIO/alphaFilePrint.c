#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	char* filePath = argv[1];
	FILE *rfp;
	int n;
	if((rfp = fopen(filePath, "rb")) == NULL){
		perror("fopen : couldn't find file.");
		exit(1);
	}
	// 파일 쓰기
	
	char alphabet_1[30];
	char alphabet_2[30];
	int idx_1 = 0;
	int idx_2 = 0;
	for(int i=0; i<10; i++){
		if(i % 2 == 0){ // 홀짝으로 구분
			fread(&alphabet_1[idx_1++], sizeof(char), 1, rfp);
		}
		else fread(&alphabet_2[idx_2++], sizeof(char), 1, rfp);
	}
	printf("%s\n", alphabet_1);
	printf("%s\n", alphabet_2);
	fclose(rfp);

}
	
