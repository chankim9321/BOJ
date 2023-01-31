#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
vector<vector<pair<int, int>>> map;
int n;
queue<pair<int, int>> q;
bool visited[101][101];
void init(){
	map.resize(n);
	for(int i=0; i<n; i++){
		map[i].resize(n);	
		for(int j=0; j<n; j++){
			int state;
			cin >> state;
			map[i][j].first = state;
			map[i][j].second = 0;
		}
	}
}
void setAreaNumber(){
	bool v[101][101];
	fill_n(&v[0][0], 101*101, false);
	int area = 1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j].first == 1 && !v[i][j]){
				queue<pair<int, int>> next;		
				next.push({i,j});
				q.push({i,j});
				map[i][j].second = area; // 지역 번호 설정
				v[i][j] = true;
				visited[i][j] = true;
				while(!next.empty()){
					int y = next.front().first;
					int x = next.front().second;
					next.pop();
					for(int k=0; k<4; k++){
						int ny = y + dy[k];
						int nx = x + dx[k];
						if(ny >= n || nx >= n || nx < 0 || ny < 0) continue; // 범위벗어날시 cancel
						if(v[ny][nx]) continue;
						if(map[ny][nx].first == 1){
							v[ny][nx] = true;
							map[ny][nx].second = area;
							next.push({ny,nx});
							q.push({ny,nx});
							visited[ny][nx] = true;
						}
					}
				}
				// 한번의 bfs가 끝나면 지역번호를 다르게 설정
				area++;
			}
		}
	}
}
int bfs(){
	int minimum = 10e8;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= n || nx >= n || nx < 0 || ny < 0) continue; // 범위벗어날시 cancel
			if(visited[ny][nx] && map[ny][nx].second != map[y][x].second){ // 만난 지역번호가 서로 다르고 이미 다리가 건설된 경우
				if(map[ny][nx].first == 1){
					minimum = min(minimum, abs(map[y][x].first));
				}
				else if(map[y][x].first == 1){
					minimum = min(minimum, abs(map[ny][nx].first));
				}
				else minimum = min(minimum, abs(map[ny][nx].first + map[y][x].first));
				continue;
			}
			if(visited[ny][nx]) continue;
			if(map[y][x].first == 1){ // 처음 출발시
				map[ny][nx].first = -1;
			}
			else{
				map[ny][nx].first = map[y][x].first - 1;
			}
			map[ny][nx].second = map[y][x].second;
			visited[ny][nx] = true;
			q.push({ny,nx});
		}
	}
	return minimum;
}
void print(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << map[i][j].first << " ";
		}
		cout << '\n';
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	fill_n(&visited[0][0], 101*101, false);
	init();
	setAreaNumber();
	cout << bfs() << '\n';
	return 0;
}
