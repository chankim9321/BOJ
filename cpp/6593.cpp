#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int visited[31][31][31];
char map[31][31][31];
int dz[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dx[] = {0,0,0,0,1,-1};
int l,r,c;
queue<tuple<int, int, int>> q;
void init(){
	fill_n(&visited[0][0][0], 31*31*31, -1);
	fill_n(&map[0][0][0], 31*31*31, ' ');
	for(int z=0; z<l; z++){
		for(int y=0; y<r; y++){
			for(int x=0; x<c; x++){
				cin >> map[z][y][x];
				if(map[z][y][x] == 'S'){ // 시작 좌표
					q.push(make_tuple(z,y,x));
					visited[z][y][x] = 0;
				}
			}
		}
	}
}
void printMap(){
	for(int z=0; z<l; z++){
		for(int y=0; y<r; y++){
			for(int x=0; x<c; x++){
				cout << map[z][y][x];
			}
			cout << '\n';
		}
		cout << "------------------------------\n";
	}
}
void bfs(){
	int answer = 10e8;
	while(!q.empty()){
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();
		if(map[z][y][x] == 'E'){
			answer = min(answer, visited[z][y][x]);	
			break;
		}
		for(int i=0; i<6; i++){
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(nz >= l || ny >= r || nx >= c || nz < 0 || ny < 0 || nx < 0) continue; // 범위 아웃
			if(visited[nz][ny][nx] != -1) continue; // 중복 방지
			if(map[nz][ny][nx] == '#') continue; // 벽을 지나갈수 없음
			visited[nz][ny][nx] = visited[z][y][x] + 1;
			q.push(make_tuple(nz, ny, nx));	
		}
	}
	if(answer == 10e8){
		cout << "Trapped!\n";
	}
	else{
		cout << "Escaped in " << answer <<  " minute(s).\n";
	}
	while(!q.empty()){
		q.pop();
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
		cin >> l >> r >> c;
		if(l == 0 && r == 0 && c == 0) break;
		init();	
		bfs();
	}
	return 0;
}
