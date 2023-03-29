#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	FILE *wfp;
	int n;
	if((wfp = fopen("alphabet.bin", "wb")) == NULL){
		perror("fopne : alphabet.bin");
		exit(1);
	}
	// 파일 쓰기
	
	char alphabet[30] = "abcdefghijklnm";
	fwrite(alphabet, sizeof(char), strlen(alphabet), wfp);
	fclose(wfp);

}
	
