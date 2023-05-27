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
	struct mymsgbuf inmesg;
	int len;
	
	int mtype;
	printf("Message Type: ");
	scanf("%d", &mtype);

	key = ftok("keyfile", 1);

	msgid = msgget(key, IPC_CREAT|0666);
	if(msgid == -1){
		perror("mssget");
		exit(1);
	}
	if((len = msgrcv(msgid, &inmesg, 80, mtype, IPC_NOWAIT)) < 0){
		printf("There is no Msg on type.\n");
	}
	else{
		printf("Received Msg : %s\n", inmesg.mtext);
		printf("Received Chaneel = %d\n", mtype);
	}

	return 0;
}
