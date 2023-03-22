#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int dp[n+1];
	
	int staticSeat;
	cin >> staticSeat;
	vector<bool> vip(n+1, false);
	for(int i=0; i<staticSeat; i++){
		int pos;
		cin >> pos;
		vip[pos] = true;
	}
	int idx = 0;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=n; i++){ // vip 좌석이 없고 양 옆의 자리만 바꿀수 있는 경우의 수
		dp[i] = dp[i-1] + dp[i-2];
	}
	int ans = 1;
	for(int i=1; i<=n; i++){
		if(vip[i]){ // vip 좌석이라면
			ans *= dp[idx];	
			idx = 0;
		}
		else{ // vip 좌석이 아니면
			idx++;		
		}
		if(i == n){ // 마지막일 경우
			ans *= dp[idx];	
		}
	}
	cout << ans << '\n';
	return 0;
}
