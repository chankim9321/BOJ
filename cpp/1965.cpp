#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int size;
	cin >> size;

	//init
	int *arr = new int(size+1);
	for(int i=1; i<=size; i++){
		cin >> arr[i];
	}
	// update
	int dp[size+1];
	fill(dp, dp+size+1, 0);
	dp[1] =	1;
	int max_element = -1;
	for(int i=2; i<=size; i++){
		int k = i;
		while(k>1){
			if(arr[k-1] < arr[i]){
				dp[i] = dp[k-1] + 1;
				break;
			}
			else k--;
		}
		max_element = max(dp[i], max_element);
	}
	// result
	cout << max_element << '\n';
	
	return 0;
}
