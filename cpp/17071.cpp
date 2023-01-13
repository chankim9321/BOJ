#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int visited[2][500001];
void bfs(int subin, int sister){
	queue<pair<int, int>> q;
	q.push({subin, 0});	
	fill_n(&visited[0][0], 2*500001, -1);
	while(!q.empty()){
		int current = q.front().first;
		int time = q.front().second; 
		q.pop();

		if(current > 500000 || current < 0 ) continue;
		if(visited[time%2][current] != -1) continue;

		visited[time%2][current] = time;
		q.push({current+1, time+1});
		q.push({current-1, time+1});
		q.push({current*2, time+1});
	}
	bool flag = false;
	for(int i=0; i<=500000; i++){
		int nextSis = sister + (i*(i+1))/2;
		if(nextSis > 500000) break;
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
