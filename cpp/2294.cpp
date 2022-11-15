#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10000000

int dp[10001];
int coins[101];
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> coins[i];
	}
	//sol
	// 각각의 동전은 자신의 가치값 부터 시작하여 목표치까지 업데이트를 시작한다.
	fill_n(&dp[0], 10001, INF);
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		dp[coins[i]] = 1;
		for(int j=coins[i]; j<=k; j++){ 
			dp[j] = min(dp[j], dp[j-coins[i]] + 1);	// 기존의 j원을 만들어 놓은 값과 j-coin원 + coin 을 비교
		}
	}
	if(dp[k] == INF){
		cout << -1 << '\n';
	}
	else cout << dp[k] << '\n';
	return 0;
}
