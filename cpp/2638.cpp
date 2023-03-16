#include <iostream>
#include <vector>
#include <queue>
#define OR ||
#define AND &&
using namespace std;

int n,m;
int visited[101][101][2];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(vector<vector<int>> &map){
	int cycle=0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> next;
	q.push({0,0});
	visited[0][0][0] = true;
	visited[0][0][1] = true;
	while(!q.empty()){
		while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i=0; i<4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny >= 0 AND nx >= 0 AND ny < n AND nx < m){
					if(map[ny][nx] == 0 AND !visited[ny][nx][0]){
						visited[ny][nx][0] = true;
						visited[ny][nx][1] = true;
						q.push({ny,nx});
					}
					else{ // 탐색했을때 치즈일 경우 두번 방문 하게 되는 경우는 녹아야만 한다.
						if(!visited[ny][nx][0] OR !visited[ny][nx][1]){ 
							if(!visited[ny][nx][0]){ // 첫번째로 방문하게 되는 경우
								visited[ny][nx][0] = true;
							}
							else{ // 두번 방문하게 되는 경우, 녹는 경우이고 이는 다음 사이클에서 방문할 점이므로 따로 큐에 넣어준다.
								visited[ny][nx][1] = true;
								next.push({ny,nx});
							}
						}
					}
				}
			}
		}
		while(!next.empty()){
			q.push(next.front());
			next.pop();
		}
		cycle++;
	}
	return cycle;
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
	cout << bfs(map)-1 << '\n';
	return 0;
}
