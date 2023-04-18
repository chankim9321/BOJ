#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
struct student{
	int id;
	char name[30];
	int grade;
};

int main(int argc, char* argv[]){
	struct student s[3];
	printf("학번    이름   점수\n");
	for(int i=0; i<3; i++){
		scanf("%d %s %d",&s[i].id, s[i].name ,&s[i].grade);
	}
	FILE* fwp;
	if(!(fwp = fopen("stu.dat", "wb"))){
		perror("fopen");
		exit(1);
	}

	fwrite(s, sizeof(struct student), 3, fwp);
	fclose(fwp);
}
