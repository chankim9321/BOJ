#include <iostream>
#include <algorithm>
#include <queue>
#define weight first
#define delay second
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int trucks, length, weight;
	cin >> trucks >> length >> weight;
	queue<int> q;
	deque<pair<int, int>> passing;
	int cnt;
	for(int i=0; i<trucks; i++){
		int truckWeight;
		cin >> truckWeight;
		q.push(truckWeight);
	}

	while(!q.empty() || !passing.empty()){
		for(int i=0; i<passing.size(); i++){
			passing[i].delay -= 1;
		}
		if(!passing.empty() && passing.front().delay == 0) passing.pop_front(); // 다 건넜다면 다리위에서 제거
		int sumWeight = 0;
		for(int i=0; i<passing.size(); i++){
			sumWeight += passing[i].weight;	
		}
		if(!q.empty() && q.front() + sumWeight <= weight && passing.size() <= length){
			passing.push_back({q.front(), length});
			q.pop();
		}
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
