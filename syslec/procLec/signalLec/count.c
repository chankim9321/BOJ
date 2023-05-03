#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
int iter = 0;
int reverse = 0;
void SigIntHandler(int signo) {
	iter = 1;
}
void SigTermHandler(int signo){
	printf("프로그램이 종료됩니다.\n");
	psignal(signo, "Signal has been occured");
	exit(1);
}
void SigUsrHandler(int signo){ // 카운트다운 역순 출력
	reverse = 1;	
	for(int i=1; i<=10; i++){
		printf("%d.. \n", i);
		if(iter == 1) break;
		sleep(1);
	}
	iter = 1;
}
void setSignal(){
	signal(SIGINT, SigIntHandler);
	signal(SIGTERM, SigTermHandler);
	signal(SIGUSR1, SigUsrHandler);
}

void doCount(){
	do{
		iter = 0;
		reverse = 0;
		for(int i=10; i>=0; i--){
			if(iter == 1) break; // SIGINT 발생이후
			if(reverse == 1) break; // SIGUSR1 발생이후
			printf("%d.. \n", i);
			sleep(1);
		}
	}while(iter);
}
int main(void) {
	setSignal();
	doCount();
	return 0;
}
