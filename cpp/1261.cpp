#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 10e8
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n,m;
int map[101][101];

int bfs(){
	int dist[101][101];
	fill_n(&dist[0][0], 101*101, INF);
	dist[1][1] = 0;	
	queue<pair<int, int>> q;
	q.push({1,1});
	while(!q.empty()){
		pair<int, int> current = q.front();
		q.pop();
		int y = current.first;
		int x = current.second;
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny > 0 && nx > 0 && ny <= n && nx <= m){
				if(map[ny][nx] == 1){
					if(dist[ny][nx] > dist[y][x] + 1){
						dist[ny][nx] = dist[y][x] + 1;
						q.push({ny,nx});
					}
				}
				else if(map[ny][nx] == 0){
					if(dist[ny][nx] > dist[y][x]){
						dist[ny][nx] = dist[y][x]; 
						q.push({ny,nx});
					}
				}
			}
		}
	}
	return dist[n][m];
}
int main(int argc, char* argv[]){
	scanf("%d %d", &m, &n);	

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d\n", bfs());
	return 0;
}
