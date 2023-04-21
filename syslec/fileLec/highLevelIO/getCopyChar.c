#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	FILE* fp1;
	FILE* fp2;
	char* path = argv[1];
	char* fname = argv[2];
	
	if(!(fp1 = fopen(argv[1], "rt"))){
		printf("Filepath error!\n");
		exit(1);
	}
	if(!(fp2 = fopen(argv[2], "wt"))){
		printf("Filepath error!\n");
		exit(1);
	}

	int data;
	while((data = getc(fp1)) != EOF){
		if(putc(data, fp2) == EOF){
			printf("putc error!\n");
			exit(1);
		}
	}

	fclose(fp1);
	fclose(fp2);

}
