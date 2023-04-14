#include <stdio.h>

// file : getGrade.c
// 학생 정보를 받아서 등급을 출력

// 구조체 원형
struct student{
	char name[30];
	int score;
};
void getGrade(struct student li[]){
	for(int i=0; i<3; i++){
		printf("%s 의 성적은 다음과 같습니다. ",li[i].name);
		int grade = li[i].score;
		if(grade >= 90) printf("등급은 A 입니다. \n");
		else if(grade < 90 && grade >= 80) printf("등급은 B 입니다. \n");
		else if(grade < 80 && grade >= 70) printf("등급은 C 입니다. \n");
		else if(grade < 70 && grade >= 60) printf("등급은 D 입니다. \n");
		else if(grade < 60) printf("등급은 F 입니다. \n");
	}
}
