#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int minTime=10e8;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(vector<vector<int>> &map){
	bool visited[n][n];
	fill_n(&visited[0][0], n*n, false);
	queue<pair<int,	int>> q;
	queue<pair<int, int>> next;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == -1){
				q.push({i,j});
				visited[i][j] = true;
			}
		}
	}
	int cycle = 0;
	while(!q.empty()){
		while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i=0; i<4; i++){
				int ny = dy[i] + y;
				int nx = dx[i] + x;
				if(ny >= 0 && nx >= 0 && ny < n && nx < n){
					if(visited[ny][nx]) continue;
					if(map[ny][nx] == 0 || map[ny][nx] == 2){
						next.push({ny,nx});
						visited[ny][nx] = true;
					}
				}
			}
		}
		cycle++;
		while(!next.empty()){
			q.push(next.front());
			next.pop();
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 0 && !visited[i][j]) return;
		}
	}
	minTime = min(minTime, cycle-1);
}
void searchAllCase(vector<vector<int>> &map, int virus){
	if(virus == 0){
		return bfs(map);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 2){
				map[i][j] = -1; // 바이러스 살포
				searchAllCase(map, virus-1);
				map[i][j] = 2;
			}
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> map(n, vector<int> (n,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int state;
			cin >> state;
			map[i][j] = state;
		}
	}
	searchAllCase(map, m);
	if(minTime == 10e8) cout << -1 << '\n';
	else cout << minTime << '\n';
	return 0;
}
