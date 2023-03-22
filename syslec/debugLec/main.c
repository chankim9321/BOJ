#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100001

int r_p(int n, int dp[]);
int dp[MAX_SIZE];

int main(){
	for(int i=0; i<=MAX_SIZE; i++){
		dp[i] = 0;
	}
	int n, result;

	printf("input any number : ");
	scanf("%d", &n);

	result = r_p(n, dp);
	printf("<Recuresion> \n");
	printf("======================================= \n");
	printf("값 : %d\n", result);
	for(int i=n; i>=0; i--){
		printf("Fibo(%d) = %d번\n", i, dp[i]);
	}
}
