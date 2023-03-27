#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int visited[1001][1001][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main(int argc, char* argv[]){
	// init
	fill_n(&visited[0][0][0], 1001*1001*2, 0);
	int N, M;
	scanf("%d %d", &N, &M);
	int arr[1001][1001];
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	// solution
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(1, make_pair(1, 0)));
	visited[1][1][0] = visited[1][1][1] = 1;
	arr[1][1] = 1;
	while(!q.empty()){
		int crashed = q.front().second.second;
		int x = q.front().second.first;
		int y = q.front().first;
		q.pop();
		if(y == N && x == M){
			printf("%d\n", visited[N][M][crashed]);
			return 0;
		}
		for(int i=0; i<4; i++){
			int next_x = x+dx[i];
			int next_y = y+dy[i];
			// 변화된 좌표가 인덱스를 벗어나지 않으면서
			if(next_x > 0 && next_y > 0 && next_x <= M && next_y <= N){
				// 맵상에서 벽, 한번도 부순적이 없으며, 방문하지 않은 곳
				if(arr[next_y][next_x] == 1 && crashed == 0 ){
					visited[next_y][next_x][crashed+1] = visited[y][x][crashed] + 1;
					q.push(make_pair(next_y, make_pair(next_x, crashed + 1)));
				}
				// 맵상에서 벽이 아니고, 방문하지 않은 곳
				if(arr[next_y][next_x] == 0 && visited[next_y][next_x][crashed] == 0){
					visited[next_y][next_x][crashed] = visited[y][x][crashed] + 1;
					q.push(make_pair(next_y, make_pair(next_x, crashed)));
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}
