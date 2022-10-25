#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	int size;
	cin >> size;
	int *dp = new int(size+1);
	fill(dp,dp+size+1,0);	
	int memory[1001][10] = {0,};
	dp[1] = 10;
	for(int i=0; i<10; i++){
		memory[1][i] = 1;
	}

	for(int i=2; i<=size; i++){
		memory[i][0] = dp[i-1];
		dp[i] += memory[i][0];
		for(int j=1; j<10; j++){
			memory[i][j] = memory[i][j-1] - memory[i-1][j-1];
			dp[i] += memory[i][j];
			dp[i] %= 10007;
		}
	}
	cout << dp[size] << '\n';
	return 0;
}

