#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#define INF 100000
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cave[126][126];

int shortestPath(int size) {
	int** path = new int* [size];
	for (int i = 0; i < size; i++) {
		path[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			path[i][j] = INF;
		}
	}
	path[0][0] = 0;
	// 0,0 부터 시작
	priority_queue<pair<pair<int,int>, int>> pq; // 첫번째, 두번째는 좌표 세번째는 거리값
	pq.push({ {0,0},0 });
	while (!pq.empty()) {
		int y = pq.top().first.first;
		int x = pq.top().first.second;
		int distance = -pq.top().second;
		pq.pop();
		if (path[y][x] < distance) continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && nx < size && ny < size) {
				int nextDistance = distance + cave[ny][nx];
				if (nextDistance < path[ny][nx]) {
					path[ny][nx] = nextDistance;
					pq.push({ {ny,nx},-nextDistance });
				}
			}
		}
	}
	int res = path[size - 1][size - 1] + cave[0][0];
	for (int i = 0; i < size; i++) {
		delete[] path[i];
	}
	delete[] path;
	return res;
}
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size;
	int testCase = 1;
	while(1){
		fill_n(&cave[0][0], 126 * 126, 0);
		cin >> size;
		if(size == 0) break;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> cave[i][j];
			}
		}
		cout << "Problem " << testCase << ": " << shortestPath(size) << '\n';
		testCase++;
	}
	return 0;
}
