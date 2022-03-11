#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
int get_slicedNumber(char* string){
	int sum=atoi(strtok(string,"+"));
	char* sliced=strtok(NULL,"+");
	while(sliced!=NULL){
		sum+=atoi(sliced);
		sliced=strtok(NULL,"+");
	}
	return sum;
}
int main(int argc,char* argv[]){
    char* string=(char*)malloc(sizeof(char)*50);
    fgets(string,sizeof(char)*50,stdin);
    string[strlen(string)-1]='\0'; // receive formula as string
	char* ptr=strtok(string,"-"); 
	int min_sum=get_slicedNumber(ptr);
	ptr=strtok(NULL,"-");
//	printf("first_sum: %d\n",min_sum);
	while(ptr!=NULL){
//		printf("slicing(except first): %s\n",ptr);
		min_sum-=change_plus_formula(ptr);
		ptr=strtok(NULL,"-");
	}
	printf("%d\n",min_sum);
    return 0;
}
