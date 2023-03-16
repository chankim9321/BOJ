#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<deque<int>> cogWheel(4, deque<int>());

// N극은 0, S극은 1
// 12시 방향의 인덱스는 0
// 3시방향과 9시방향의 인덱스는 각각 2, 6 이다.
// solution
// 1. 3시방향 극을 방향에 맞게 톱니바퀴를 돌린다.
// 2. 양 옆으로 맞 닿은 3시 방향과 9시방향의 톱니를 큐에 넣는다.
// 3. 큐에서 하나씩 빼어 맞물려있는 톱니를 업데이트한다.
void sol(int cogNumber, int direction){
	
}
int main(int argc, char* argv[]){
	for(int i=0; i<4; i++){
		for(int j=0; j<8; j++){
			int pole;
			scanf("%1d",&pole);
			cogWheel[i].push_back(pole);
		}
	}
	int rotates;
	scanf("%d",&rotates);
	for(int i=0; i<rotates; i++){
		int cogNumber, direction;
		scanf("%d %d", &cogNumber, &direction);
		sol(cogNumber, direction);
	}
}
