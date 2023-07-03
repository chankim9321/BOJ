#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mymsgbuf{
	long mtype;
	char mtext[80];
};

int main(int argc, char* argv[]){
	key_t key;
	int msgid;
	struct mymsgbuf mesg;
	
	char* msgType = argv[1];
	char* msg = argv[2];

	key = ftok("keyfile", 1);

	msgid = msgget(key, IPC_CREAT|0666);
	if(msgid == -1){
		perror("mssget");
		exit(1);
	}
	char a[10];
	strcpy(a, msgType);
	mesg.mtype = a[0] - '0'; // 메시지 채널 지정
	strcpy(mesg.mtext, argv[2]);

	if(msgsnd(msgid, (void*)&mesg, 80, IPC_NOWAIT) == -1){
		perror("msgsnd");
		exit(1);
	}
	printf("Your message is successfully sent! (mesgType : %ld)\n ", mesg.mtype);
	return 0;
}
