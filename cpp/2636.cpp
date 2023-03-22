#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
int cheese, cnt;
bool visited[101][101];
void bfs(vector<vector<int>> &matrix){
	cheese = 0;
	cnt = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> next;
	q.push({0,0});
	visited[0][0] = true;
	while(!q.empty()){
		cheese = q.size(); // 녹기전 치즈의 갯수
		// 한 사이클
		while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i=0; i<4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny >= 0 && nx >= 0 && ny < n && nx < m){
					if(!visited[ny][nx] && matrix[ny][nx] == 1){ // 녹기전 치즈의 갯수 체크
						next.push({ny,nx});
					}
					else if(!visited[ny][nx] && matrix[ny][nx] == 0){
						q.push({ny,nx});
					}
					visited[ny][nx] = true;
				}
			}
		}
		while(!next.empty()){
			q.push(next.front());
			next.pop();
		}
		cnt++;
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int state;
			cin >> state;
			matrix[i][j] = state;
		}
	}
	bfs(matrix);
	cout << cnt-1 << '\n' << cheese << '\n';
	return 0;
}
