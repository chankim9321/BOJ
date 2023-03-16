#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	int size; 
	cin >> size; 
	int mod = 9901;
	int dp[size+1][3];
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for(int i=2; i<=size; i++){
		dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % mod;
		dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
		dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod;
	}
	cout << (dp[size][0] + dp[size][1] + dp[size][2]) % mod << '\n';
	return 0;
}
