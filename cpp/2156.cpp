#include <iostream>
#include <algorithm>
#include <vector>
#define DEBUG_MODE 0
using namespace std;

int main(int argc, char* argv[]){
	int size;
	int opt_max=0;
	cin >> size;
	int *dp = new int[size+1];
	fill(dp, dp+size+1, 0);
	vector<int> drinks;
	drinks.push_back(0);
	for(int i=0; i<size; i++){ // init
		int wine;
		cin >> wine;
		drinks.push_back(wine);
	}
	if(size < 2){
		dp[1] = drinks[1];
		opt_max = dp[1];
	}
	else{
		dp[1] = drinks[1];
		dp[2] = dp[1] + drinks[2];
		opt_max = dp[2];
	}
	for(int i=3; i<=size; i++){
		dp[i] =	max(dp[i-2] + drinks[i], dp[i-3] + drinks[i-1] + drinks[i]);
		opt_max = max(opt_max, dp[i]);
	}
	#if DEBUG_MODE
	for(int i=1; i<=size; i++){
		cout << dp[i] << ", ";
	}
	cout << '\n';
	#endif
	cout << opt_max << '\n';
	return 0;
}
