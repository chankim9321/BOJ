#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#define long long ll
using namespace std;

// 가로선, 세로선, 가로선을 놓을 수 있는 위치의 개수 H
int horiLine, vertLine, H;
int result = 10e8;

bool isPerfect(vector<vector<int>>& map) {
	for (int i = 1; i <= vertLine; i++) {
		int currentPos = i;
		for (int j = 1; j <= H; j++) {
			if (map[currentPos][j] == 1) currentPos++; // 오른쪽에 길이 있다면 이동
			else if (map[currentPos - 1][j] == 1) currentPos--; // 왼쪽에 길이 있다면 이동
		}
		if (currentPos != i) return false; // 처음과 다르다면 문제 요구사항과 맞지 않으므로 pass
	}
	return true; // 모든 사다리 입구번호가 출구 번호와 동일하다면 참을 반환
}
void LineSelection(vector<vector<int>>& map, int start, int cnt) {
	if (cnt > 3) return; // 가로선이 3보다 크다면 -1를 출력하므로 최적화작업을 캔슬한다
	if (isPerfect(map) == true) {
		result = min(result, cnt);
		return;
	}
	for (int i = start; i <= H; i++) {
		for (int j = 1; j < vertLine; j++) {
			// 현재위치에서 양옆에 사다리가 존재하면 pass
			if (map[j][i] == 1) continue;
			if (map[j - 1][i] == 1) continue;
			if (map[j + 1][i] == 1) continue;

			map[j][i] = 1;
			LineSelection(map, i, cnt + 1);
			map[j][i] = 0;
		}
	}
}
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	// init
	cin >> vertLine >> horiLine >> H;
	if (horiLine == 0) {
		cout << 0 << '\n';
		return 0;
	}
	vector<vector<int>> map(vertLine+1, vector<int>(H+1, 0));
	for (int i = 0; i < horiLine; i++) {
		int a, b; 
		cin >> a >> b;
		map[b][a] = 1;
	}
	// sol
	LineSelection(map, 1, 0);
	if (result == 10e8) cout << -1 << '\n';
	else cout << result << '\n';

}

