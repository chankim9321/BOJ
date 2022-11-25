#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 100001
using namespace std;

int cnt[MAX];
int next_x[3] ={-1,1,2};
bool visitedPos[MAX] = { false, };
int roadTracker[MAX] = {0,};

void sol(int subinPos){
	queue<pair<int, int>> q;
	q.push({subinPos, 0});
	visitedPos[subinPos] = true;	
	while(!q.empty()){
		pair<int, int> present = q.front();
		q.pop();
		cnt[present.first] = min(cnt[present.first], present.second);
		for(int i=0; i<3; i++){
			int nextPos;
			if(i==2){
				nextPos = present.first * next_x[i];
			}
			else{
				nextPos = present.first + next_x[i];
			}
			if(nextPos < MAX && nextPos > -1){
				if(!visitedPos[nextPos]){
					visitedPos[nextPos] = true;
					roadTracker[nextPos] = present.first;
					q.push({nextPos, present.second+1});
				}
			}
		}
	}
}

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	fill_n(&cnt[0], MAX, MAX);
	int subinPos, brotherPos;
	cin >> subinPos >> brotherPos;
	if(subinPos > brotherPos){ // 수빈의 포지션이 동생보다 앞선다면 뒤로 한칸씩 가는 수밖에 없음.
		cout << subinPos - brotherPos << '\n';
		for(int i=subinPos; i>=brotherPos; i--){
			cout << i << " ";
		}
		cout << '\n';
		return 0;
	}
	else {
		sol(subinPos);
		cout << cnt[brotherPos] << '\n';

		// tracking
		stack<int> road;
		int k=brotherPos;
		road.push(k); // 동생위치
		while(k != subinPos){
			road.push(roadTracker[k]);
			k = roadTracker[k];
		}

		// print trackResult
		while(!road.empty()){
			cout << road.top() << " ";
			road.pop();
		}
		cout << '\n';

		return 0;
	}
}
