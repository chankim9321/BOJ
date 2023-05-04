#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	for(int i=1; i<=180; i++){
		printf("playing %d seconds.\n", i);
		sleep(1);
	}
	return 0;
}
