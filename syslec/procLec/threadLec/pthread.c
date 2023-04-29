#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void *arg){
	int i;
	for(i=0; i<3; i++){
		sleep(2);
		puts("Thread is running..");
	}
	return 10;
}
int main(int argc, char* argv[]){
	int state;
	void* a;
	pthread_t tid;
	if((state = pthread_create(&tid, NULL, thread_function, NULL)) != 0){
		perror("thread create error");
		exit(1);
	}
	if(pthread_join(tid, &a) != 0){
		perror("thread join error");
		exit(1);
	}
	puts("main function is end");
	printf("%d\n", *(int*)a);
	return 0;
}

