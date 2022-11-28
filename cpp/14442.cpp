#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int width, height, chance;
int map[1001][1001];
int visited[1001][1001][11];
// visited 의 세번째 인덱스는 찬스의 갯수
int sol(){
	queue<pair<pair<int, int>, int>> q;
	q.push({{1,1}, chance});
	visited[1][1][chance] = 1;
	while(!q.empty()){
		pair<int, int> presentPos = q.front().first;
		int y = presentPos.first;
		int x = presentPos.second;
		int wallBreak = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			// 다음 이동할 좌표
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(nx >= 1 && ny >= 1 && ny <= height && nx <= width){
				if(visited[ny][nx][wallBreak] == 0){ // 방문하지 않은 점 
					if(map[ny][nx] == 1 && wallBreak != 0 ){ // 벽이 존재한다면 기회를 소모하고 벽을 부순뒤 방문
						visited[ny][nx][wallBreak-1] = visited[y][x][wallBreak] +1;
						q.push({{ny,nx},wallBreak-1});
					}
					if(map[ny][nx] == 0){ // 벽이 존재하지 않는다면 기회는 그대로
						visited[ny][nx][wallBreak] = visited[y][x][wallBreak] +1;	
						q.push({{ny,nx},wallBreak});
					}
				}
			}
		}
	}
	int result=10e8;
	for(int i=0; i<=chance; i++){
		if(visited[height][width][i] == 0) continue;
		result = min(visited[height][width][i], result);
	}
	if(result == 10e8) return -1;
	return result;
}
int main(int argc, char* argv[]){
	scanf("%d %d %d", &height, &width, &chance);
	fill_n(&visited[0][0][0],1001*1001*11, 0);
	for(int i=1; i<=height; i++){
		for(int j=1; j<=width; j++){
			scanf("%1d",&map[i][j]);
		}
	}
	printf("%d\n", sol());
	
	return 0;
}
