#include <iostream>
#define ll long long
using namespace std;

ll dp[100];
ll fibo(int n){
	if(dp[n] != 0) return dp[n];
	if(n == 1 || n == 2) return 1;
	return dp[n] = fibo(n-1) + fibo(n-2);	
}
int main(){
	for(int i=0; i<100; i++){
		dp[i] = 0;
	}
	int n;
	cin >> n;
	cout << fibo(n) << '\n';
	return 0;
}
