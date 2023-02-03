#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

vector<vector<int>> map;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int height, width, chance;
int visited[2][11][1001][1001]; // 0은 낮 1은 밤
void init(){
	fill_n(&visited[0][0][0][0], 2*11*1001*1001, -1);
	cin >> height >> width >> chance;
	map.resize(height);
	for(int i=0; i<height; i++){
		map[i].resize(width);
		for(int j=0; j<width; j++){
			scanf("%1d", &map[i][j]);
		}
	}
}
void printMap(){
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
}
void bfs(){
	int answer = 10e8;
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0,chance,0,0));
	visited[0][chance][0][0] = 1;
	while(!q.empty()){
		int dayState = get<0>(q.front());
		int ch = get<1>(q.front());
		int y = get<2>(q.front());
		int x = get<3>(q.front());
		q.pop();
		//cout << "current weight = " << visited[dayState][ch][y][x] << '\n';
		if(y == height - 1 && x == width - 1){
			answer = min(answer, visited[dayState][ch][y][x]);
			break;
		}
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= height || nx >= width || ny < 0 || nx < 0) continue;
			if(visited[(dayState+1)%2][ch][ny][nx] != -1) continue;
			if(map[ny][nx] == 1){ // 벽일 때
				if(ch > 0){ // 찬스가 있을 때
					if(dayState == 0){ // 낮일 때
						visited[dayState+1][ch-1][ny][nx] = visited[dayState][ch][y][x] + 1;
						q.push(make_tuple(dayState + 1, ch - 1, ny, nx));
					}
					else{ // 밤일 때
						//visited[dayState][chance][y][x]++;
						visited[dayState-1][ch][y][x] = visited[dayState][ch][y][x] + 1;
						q.push(make_tuple(dayState - 1, ch, y, x)); // 제자리에서 비용만 증가하고 다시 낮으로
					}
				}
			}
			else if(map[ny][nx] == 0){ // 허공일 때
				visited[(dayState+1)%2][ch][ny][nx] = visited[dayState][ch][y][x] + 1;
				q.push(make_tuple((dayState+1)%2, ch, ny, nx));
			}
		}
	}
	if(answer == 10e8) cout << -1 << '\n';
	else cout << answer << '\n';
}
int main(int argc, char* argv[]){
	init();
	bfs();
	return 0;
}
