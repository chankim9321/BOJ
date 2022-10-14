#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int size;
	cin >> size;

	int *dp = new int[size];
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<size; i++){
		dp[i] =	 dp[i-1] + dp[i-2];
	}
	cout << dp[size-1] << '\n';
	return 0;
}
