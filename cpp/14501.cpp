#include <iostream>
#include <vector>
#define DEBUG_MODE 0
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
// ------------------ init -------------------------
	int days, hour, pay;
	vector<pair<int, int> > v;
	cin >> days;
	int *DP = new int[days+1];
	v.push_back(make_pair(0,0));
	for(int i=1; i<=days; i++){
		cin >> hour >> pay;
		v.push_back(make_pair(hour, pay));
		DP[i] = pay;
	}
//--------------------------------------------------
	int ans=DP[1];

	for(int i=1; i<=days; i++){
		int next_idx = v[i].first + i; // 현재로부터 다음 일정 가능까지 가능한 소요시간 이는 다음 스케줄의 인덱스를 의미한다.
		if(next_idx > days ) continue; // 인덱스를 넘어가는 경우, 소요기간 누적이 인덱스를 넘어가는 경우

		for(int k = next_idx; k <= days; k++){ // 가능한 모든 스케줄
			if(k + v[k].first-1 > days) continue; // 일정 소요기간이 은퇴날짜를 넘어가면 패스한다.
			DP[k] = max(DP[k], v[k].second + DP[i]); // 원본값이랑 비교한 결과와 현재 최대로 업데이트된 값중 큰값을 저장
		}
	}
	for(int i=1; i<=days; i++){
		if(v[i].first-1 + i > days) continue;
		ans = max(ans, DP[i]);
	}
	#if DEBUG_MODE
	for(int i=1; i<=days; i++){
		cout << DP[i] << "-";
	}
	cout << '\n';
	#endif
	cout << ans << '\n';
	return 0;
}
