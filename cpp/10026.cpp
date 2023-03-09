#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<char>> map;
vector<vector<char>> re_map;
bool visited[101][101];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
void dbf(){while(getchar() != '\n');};
void init(){
	cin >> n;
	map.resize(n);
	re_map.resize(n);
	dbf();
	for(int i = 0; i<n; i++){
		map[i].resize(n);
		re_map[i].resize(n);
		for(int j=0; j<n; j++){
			scanf("%1c", &map[i][j]);
			if(map[i][j] == 'G'){
				re_map[i][j] = 'R';
			}
			else re_map[i][j] = map[i][j];
		}
		dbf();
	}
}
void bfs(int y, int x, vector<vector<char>> &mat){
	queue<pair<int, int>> q;	
	q.push({y,x});
	visited[y][x] = true;
	char ch = mat[y][x];
	while(!q.empty()){
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(mat[ny][nx] == ch && !visited[ny][nx]){
				visited[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}
}
void sol(){
	int area_1 = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				bfs(i,j, map);
				area_1++;
			}
		}
	}
	fill_n(&visited[0][0], 101*101, false);
	int area_2 = 0; 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				bfs(i,j, re_map);
				area_2++;
			}
		}
	}
	cout << area_1 << " " << area_2 << '\n';
}
int main(int argc, char *argv[]){
	init();	
	sol();
	return 0;
}
