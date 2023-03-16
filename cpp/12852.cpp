#include <iostream>
#include <vector>
#define MAX_VALUE 10e8
using namespace std;

void pathTracking(vector<pair<int, int>> &dp, int start){
	if(start == 1) return;
	cout << dp[start].second << " ";
	pathTracking(dp, dp[start].second);
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> dp(n+1, {MAX_VALUE, 0});
	dp[1] = {0,1};

	for(int i=2; i<=n; i++){
		dp[i].second = i;
		int flag;
		if(i % 2 == 0){
			if(dp[i].first > dp[i/2].first + 1){
				dp[i].first = dp[i/2].first + 1;
				flag = 1;
			}
		}
		if(i % 3 == 0){
			if(dp[i].first > dp[i/3].first + 1){
				dp[i].first = dp[i/3].first + 1;
				flag = 2;
			}
		}
		if(i>0){
			if(dp[i].first > dp[i-1].first + 1){
				dp[i].first = dp[i-1].first + 1;
				flag = 3;
			}
		}
		switch(flag){
			case 1:
				dp[i].second = i/2;
				break;
			case 2:
				dp[i].second = i/3;
				break;
			default:
				dp[i].second = i-1;
				break;
		}
	}
	cout << dp[n].first << '\n';
	cout << n << " ";
	pathTracking(dp, n);
	cout << '\n';
	return 0;
}
