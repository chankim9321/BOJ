#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	int id;
	char name[30];
	int grade;
};

struct student s[3];
void search(){
	int id_input;
	printf("검색할 학생의 학번 입력: ");
	scanf("%d", &id_input);
	for(int i=0; i<3; i++){
		if(s[i].id == id_input){
			printf("학번 : %d    이름: %s     점수: %d\n", s[i].id, s[i].name, s[i].grade);
			break;
		}
	}
}
int main(int argc, char* argv[]){
	char* datafile = argv[1];
	FILE* frp;
	
	if(!(frp = fopen(datafile, "rb"))){
		perror("fopen");
		exit(1);
	}

	if(fread(s, sizeof(struct student), 3, frp) != 3){
		perror("fread");
		exit(1);
	}
	search();
	fclose(frp);
	return 0;

}
