#include <stdio.h>

// file : getAvr.c
// 학생정보를 받아서 성적의 평균을 출력한다

// 구조체 원형
struct student {
	char name[30];
	int score;
};

void printAvr(struct student li[]){
	int sum = 0;
	for(int i=0; i<3; i++){
		sum += li[i].score;
	}
	printf("평균은 %d 입니다!\n", sum/3);
}
