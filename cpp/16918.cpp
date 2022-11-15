#include <iostream>
#include <stdio.h>
#include <algorithm>
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
void installBomb(queue<pair<int, int>> &bomb){
	for(int i=0; i<R; i++){ 
		for(int j=0; j<C; j++){
			if(map[i][j] == '.'){
				map[i][j] = 'O';
				bomb.push({i, j});
			}
		}
	}
	N--;
}
queue<pair<int, int>> predictBang(queue<pair<int, int>> &bomb){
	queue<pair<int, int>> predict;
	int cnt = bomb.size();
		while(cnt > 0){
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
			cnt--;
		}
	return predict;
}
void explodeBomb(queue<pair<int, int>> &predict, queue<pair<int, int>> &anotherBomb){
	int pre = predict.size();
	int ano = anotherBomb.size();
	for(int i = 0; i<pre; i++){
		pair<int, int> prePos = predict.front();
		predict.pop();
		for(int j = 0; j<ano; j++){
			pair<int, int> anoPos = anotherBomb.front();
			anotherBomb.pop();
			if(prePos != anoPos){
				anotherBomb.push(anoPos);
			}
		}
		predict.push(prePos);
	}
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
	queue<pair<int, int>> predict1;
	queue<pair<int, int>> predict2;
	scanf("%d %d %d", &R, &C, &N);
	// 초기 폭탄을 설치한다. 
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf(" %1c",&map[i][j]);
			if(map[i][j] == 'O') bomb1.push({i, j}); // 초기 폭탄설치 위치를 기억
		}
	}		
	// 설치된 폭탄의 폭발범위 좌표를 미리 예측한다.
	predict1 = predictBang(bomb1);
	N--;
	while(N>0){
		installBomb(bomb2);
		predict2 = predictBang(bomb2);
		if(N==0) break;
		explodeBomb(predict1, predict2);
		predict2 = predictBang(predict2);
		if(N==0) break;
		installBomb(bomb1);
		predict1 = predictBang(bomb1);
		if(N==0) break;
		explodeBomb(predict2, predict1);
		predict1 = predictBang(predict1);	
	}
	printf("--------------------------------\n");
	showMap();
	return 0;
}
