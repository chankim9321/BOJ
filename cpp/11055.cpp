#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size;
	cin >> size;
	int arr[size];
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
	// solution

	int dp[size];
	dp[0] = arr[0];
	int res = dp[0];
	for(int i=1; i<size; i++){
		dp[i] = arr[i];
		for(int j=i-1; j>=0; j--){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], arr[i] + dp[j]);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res << '\n';
	return 0;
}
