#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int visited[2][500001];
void bfs(int subin, int sister){
	queue<pair<int, int>> q; // 위치값, 시간
	q.push({subin, 0});	
	fill_n(&visited[0][0], 2*500001, -1);
	while(!q.empty()){
		int current = q.front().first;
		int time = q.front().second; 
		q.pop();

		if(current > 500000 || current < 0 ) continue;
		if(visited[time%2][current] != -1) continue;

		// 도착한 시간을 짝/홀 간격으로 저장
		// 문제 설명에서 언니는 계속해서 움직여야한다. 하지만 동생보다 앞에 있는 경우에서는 가만히 있는것이 최적이므로
		// 1초뒤 -1 2초뒤 +1을 해주면 가만히 있는 경우가 된다.
		// 즉 2초간격으로 왔다갔다 할 수 있다.
		visited[time%2][current] = time; 
		q.push({current+1, time+1});
		q.push({current-1, time+1});
		q.push({current*2, time+1});
	}
	bool flag = false;
	// 파라미터 서칭
	for(int i=0; i<=500000; i++){ // i는 동생기준에서 시간
		// 기존 동생의 위치에서 1..2..3.. 가속이 붙으므로 수열의 합을 더해준다
		int nextSis = sister + (i*(i+1))/2;
		if(nextSis > 500000) break;
		// 언니는 2초를 간격으로 사실상 왔다갔다 할 수 있음.
		// 대신 동생보다 반드시 먼저 앞질러서 왔다갔다 해야만 한다.
		// 밑에 코드가 의미하는 바는 언니가 기다리고 있고, 동생 보다 먼저 앞질러 왔을 경우의 조건이다
		// case 1) 5 17
		// 5 10 20
		// 17 18 20
		// case 2) 16 4
		// 16 15 14 13 12
		// 4  5  7  10 14
		if(visited[i%2][nextSis] != -1 && visited[i%2][nextSis] <= i){ 
			cout << i << '\n';
			flag = true;
			break;
		}
	}
	if(!flag){
		cout << -1 << '\n';
	}
}
int main(int argc, char* argv[]){
	int subin, sister;
	cin >> subin >> sister;	
	bfs(subin, sister);
	return 0;
}
