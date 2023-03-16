#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
bool visited[101][101];
int main(int argc, char* argv[]){
	int height, width;
	scanf("%d %d", &height, &width);
	int map[height+1][width+1];
	//fill_n(&map[0][0], (height+1)*(width+1), 0);	

	for(int i=1; i<=height; i++){
		for(int j=1; j<=width; j++){
			scanf("%1d",&map[i][j]);
		}
	}
	queue<pair<int, int> > q;
	q.push({1, 1});
	visited[1][1] = true;
	map[1][1] = 1;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny > 0 && nx > 0 && ny < height+1 && nx < width+1){
				if(!visited[ny][nx] && map[ny][nx] != 0){
					q.push({ny, nx});
					map[ny][nx] = map[y][x] + 1;
					visited[ny][nx] = true;
				}
			}
		}
	}
	printf("%d\n",map[height][width]);
	
}
