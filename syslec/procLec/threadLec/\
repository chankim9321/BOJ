#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int n = 2;
pthread_mutex_t mutex;
void* Count(void *arg){
	int i;
	char* name = (char*)arg;
	pthread_mutex_lock(&mutex);
	for(i=1; i<10; i++){
		sleep();
		printf("%s gugu : %d x %d = %d\n", name, n, i, n*i);	
	}
	n++;
	pthread_mutex_unlock(&mutex);
	return NULL;
}
int main(int argc, char* argv[]){
	int state;
	pthread_t tid1, tid2;
	pthread_mutex_init(&mutex, NULL);
	if((state = pthread_create(&tid1, NULL, Count, (void*)"thread1")) != 0){
		perror("thread1 create error");
		exit(1);
	}
	if((state = pthread_create(&tid2, NULL, Count, (void*)"thread2")) != 0){
		perror("thread2 create error");
		exit(1);
	}
	if(pthread_join(tid1, NULL) != 0){
		perror("thread1 join error");
		exit(1);
	}
	if(pthread_join(tid2, NULL) != 0){
		perror("thread2 join error");
		exit(1);
	}
	puts("main function is end");
	return 0;
}

