#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n,m;
int maxRoom = 0;
int bfs(vector<vector<int>> map){
	queue<pair<int, int>> q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == 2){
				q.push({i,j});
			}
		}
	}
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if(ny >= 0 && nx >= 0 && ny < n && nx < m){
				if(map[ny][nx] == 0){
					q.push({ny,nx});
					map[ny][nx] = 2;
				}
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
void searchAllCase(vector<vector<int>> &map, int wall){
	if(wall == 3){ // 벽이 3개라면 bfs시도
		maxRoom = max(bfs(map), maxRoom);
		return;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == 0){
				map[i][j] = 1;
				searchAllCase(map, wall+1);
				map[i][j] = 0;
			}
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> map(n, vector<int> (m,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int value;
			cin >> value;
			map[i][j] = value;
		}
	}
	searchAllCase(map, 0);	
	cout << maxRoom << '\n';
	return 0;
}
