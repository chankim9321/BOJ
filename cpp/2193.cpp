#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int size;
	cin >> size;

	long long *dp = new long long[size+1];
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3; i<=size; i++){
		dp[i] =	 dp[i-1] + dp[i-2];
	}
	cout << dp[size] << '\n';
	return 0;
}
