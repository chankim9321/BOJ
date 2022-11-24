#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int cnt[100001];
int next_x[3] ={-1,1,2};
bool visitedPos[100001] = { false, };
int roadTracker[100001] = {0,};

void sol(int subinPos, int brotherPos){
	queue<pair<int, int>> q;
	q.push({subinPos, 0});
	while(!q.empty()){
		pair<int, int> present = q.front();
		q.pop();
		cnt[present.first] = min(cnt[present.first], present.second);
		visitedPos[present.first] = true;	
		for(int i=0; i<3; i++){
			int nextPos;
			if(i==2){
				nextPos = present.first * next_x[i];
				if(nextPos < 100001) roadTracker[nextPos] = present.first;
			}
			else{
				nextPos = present.first + next_x[i];
				if(nextPos < 100001) roadTracker[nextPos] = present.first;
			}
			if(nextPos < 100001 && !visitedPos[nextPos]){
				q.push({nextPos, present.second+1});
			}
		}
	}
}

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	fill_n(&cnt[0], 100001, 100001);
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
		sol(subinPos, brotherPos);
		cout << cnt[brotherPos] << '\n';

		stack<int> road;
		int k=brotherPos;
		road.push(k); // 동생위치
		while(k != subinPos){
			road.push(roadTracker[k]);
			k = roadTracker[k];
		}
		road.push(k); // 수빈 위치
		while(!road.empty()){
			cout << road.top() << " ";
			road.pop();
		}
		cout << '\n';

		return 0;
	}
}
