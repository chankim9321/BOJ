#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int height, width, obstacle, strength, start_y, start_x, end_y, end_x;
int map[101][101];
int visited[101][101];

bool bfs(){
	queue<tuple<int, int, int>> q; // 좌표값과 남은 힘
	//int nextL = map[start.first][start.second]; // 스타트 지점의 높이
	q.push(make_tuple(start_y, start_x, strength)); // 시작점
	visited[start_y][start_x] = strength;
	while(!q.empty()){
		tuple<int, int, int> present = q.front();
		q.pop();
		int y = get<0>(present); 
		int x = get<1>(present);
		int str = get<2>(present);
		int l = map[y][x]; // 현재칸 높이
		visited[y][x] = str;
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nextL = map[ny][nx]; // 다음칸 높이
			if(ny > 0 && nx > 0 && ny <= height && nx <= width){
				if(visited[ny][nx] < str-1){
					if(nextL <= l) { // 다음 칸의 높이가 현재 높이보다 낮거나 같은 경우
						q.push(make_tuple(ny,nx,str-1));	
					}
					else{ // 다음 칸의 높이가 큰 경우
						if((nextL - l) <= str){ // 점프해야 할 높이보다 힘이 많다면 이동가능.
							q.push(make_tuple(ny,nx,str-1));
						}
					}
				}
			}
		}
	}
	if(visited[end_y][end_x] != 0) return true;
	else return false;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int testCase;
	cin >> testCase;
	for(int i=0; i<testCase; i++){
		fill_n(&map[0][0], 101*101, 0);
		fill_n(&visited[0][0], 101*101, 0);
		cin >> height >> width >> obstacle >> strength >> start_y >> start_x >> end_y >> end_x;
		for(int j=0; j<obstacle; j++){
			int y,x,l;
			cin >> y >> x >> l;
			map[y][x] = l;
		}
		if(bfs()){
			cout << "잘했어!!" << '\n';
		}
		else cout << "인성 문제있어??" << '\n';
	}
	return 0;
}
