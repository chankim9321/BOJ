#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// init
	int size;
	cin >> size;
	int arr[size];
	for(int i=0; i<size; i++){
		cin >> arr[i];	
	}
	// sol
	int dp[size];
	fill_n(&dp[0], size, 1);
	int res = dp[0];
	for(int i=1; i<size; i++){
		for(int j=0; j<i; j++){
			if(arr[i] < arr[j]){
				dp[i] = max(dp[i], dp[j] +1);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res << '\n';
	return 0;
}
