#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
vector<vector<int>> map;
int n;
queue<pair<int, int>> q;
bool visited[101][101];
void init(){
	map.resize(n);
	for(int i=0; i<n; i++){
		map[i].resize(n);	
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){ // 각 섬에서 출발
				visited[i][j] = true;
				q.push({i,j});
			}
		}
	}
}
int bfs(){
	int minimum = -10e8;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= n || nx >= n || nx < 0 || ny < 0) continue; // 범위벗어날시 cancel
			if(visited[ny][nx] && map[ny][nx] != 1){
				minimum = max(minimum, map[ny][nx] + map[y][x]);	
				continue;
			}
			if(map[y][x] == 1){ // 처음 출발시
				map[ny][nx] = -1;
				visited[ny][nx] = true;
				q.push({ny,nx});
			}
			else{
				map[ny][nx] = map[y][x] - 1;
				visited[ny][nx] = true;
				q.push({ny,nx});
			}
		}
	}
	return abs(minimum);
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	init();
	cout << bfs() << '\n';
	return 0;
}
