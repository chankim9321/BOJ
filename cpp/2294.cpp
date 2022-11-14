#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000

int dp[101][10001];
int coins[101];
int solution(int n, int k){
	if(n == 0 && k > 0) return INF;
	if(k == 0) return 0;

	int rest = k % coins[n];
	int divideRes = k / coins[n];
	return min(solution(n-1, rest) + divideRes, solution(n-1, k));
}
int main(int argc, char* argv[]){
	int n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> coins[i];
	}
	//sol
	fill_n(&dp[0][0], 11*10001, 0);

	int res = solution(n,k);
	if(res >= INF){
		cout << -1 << '\n';
	}
	else{
		cout << res << '\n';
	}
	return 0;
}
