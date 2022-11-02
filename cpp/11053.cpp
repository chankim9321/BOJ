#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//init
	int size;
	cin >> size;
	int *arr= new int(size);
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
	// solution
	int *dp = new int(size);
	int result =0;
	fill(dp, dp+size, 0);
	dp[0] = 1;
	for(int i=1; i<size; i++){
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[j], dp[i]);
			}
		}
		dp[i]++;
	}
	for(int i=0; i<size; i++){
		result = max(result, dp[i]);
	}
	cout << result << '\n';
	return 0;
}
