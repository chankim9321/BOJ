#include <stdio.h>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

char map[201][201];
int R,C,N;

void showMap(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
void installBomb(){
	for(int i=0; i<R; i++){ 
		for(int j=0; j<C; j++){
			if(map[i][j] == '.'){
				map[i][j] = 'O';
			}
		}
	}
	N--;
}
queue<pair<int, int>> predictBang(){
	queue<pair<int, int>> bomb;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] == 'O'){
				bomb.push({i,j});
			}
		}
	}
	queue<pair<int, int>> predict;
	while(!bomb.empty()){
		pair<int, int> bombPos = bomb.front();	
		bomb.pop();
		int	y = bombPos.first;
		int x = bombPos.second;
		predict.push({y, x});
		for(int i=0; i<4; i++){ 
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && nx >= 0 && ny < R && nx < C){
				predict.push({ny, nx}); // 터지는 자리의 좌표를 큐에 삽입
			}
		}
	}
	return predict;
}
void explodeBomb(queue<pair<int, int>> &predict){
	while(!predict.empty()){ // 터진 자리 일괄 수정
		pair<int, int> pos = predict.front();
		predict.pop();
		map[pos.first][pos.second] = '.';
	}
	N--;
}
int main(int argc, char* argv[]){
	queue<pair<int, int>> bomb1;
	queue<pair<int, int>> bomb2; 
	scanf("%d %d %d", &R, &C, &N);
	// 초기 폭탄을 설치한다. 
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf(" %1c",&map[i][j]);
			if(map[i][j] == 'O') bomb1.push({i, j}); // 초기 폭탄설치 위치를 기억
		}
	}		
	bomb1 = predictBang();
	N--;
	while(N>0){
		installBomb();
		if(N==0) break;
		explodeBomb(bomb1);
		bomb2 = predictBang();
		if(N==0) break;
		installBomb();
		if(N==0) break;
		explodeBomb(bomb2);
		bomb1 = predictBang();
	}
	printf("--------------------------------\n");
	showMap();
	return 0;
}
