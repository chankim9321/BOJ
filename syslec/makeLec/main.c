#include <stdio.h>
#include <string.h>
struct student{
	char name[30];
	int score;
};

// 라이브러리 함수 원형
void printAvr(struct student li[]);
void getGrade(struct student li[]);

int main(int argc, char *argv[]){
	struct student list[3] ={
		{"kim", 100},
		{"lim", 50},
		{"han", 70}
	};

	printAvr(list);
	getGrade(list);
}
