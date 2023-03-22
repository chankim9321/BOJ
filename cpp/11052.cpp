#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int cards;
	cin >> cards;
	int pack[cards+1];
	int dp[cards+1]; // 인덱스는 카드의 수이며 카드의 수 별 최대의 금액을 가지고있는 배열이다.
	for(int i=1; i<=cards; i++){
		cin >> pack[i];
		dp[i] = pack[i];
	}

	for(int i=2; i<=cards; i++){
		for(int j = i-1; j>=i-j; j--){
			dp[i] = max(dp[i], dp[j]+dp[i-j]);
		}
	}
	cout << dp[cards] << '\n';

	return 0;
	
}
