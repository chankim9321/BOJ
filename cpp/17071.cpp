#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int visited[500001];
void bfs(int subin, int sister){
	queue<int> q;
	q.push(subin);	
	visited[subin] = 0;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(int i=0; i<3; i++){
			int next;
			if(i == 0) next = current + 1;
			else if(i == 1) next = current - 1;
			else next = current * 2;	
			if(next > 500000 || next < 0 ) continue;
			if(visited[current] + 1 < visited[next]){
				visited[next] = visited[current] + 1;	
				q.push(next);
			}
		}
	}
	bool flag = false;
	for(int i=0; i<=500000; i++){
		int nextSis = sister + (i*(i+1))/2;
		if(nextSis > 500000) break;
		if(visited[nextSis] != 500001 && visited[nextSis] <= i){
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
	fill_n(&visited[0], 500001, 500001);
	bfs(subin, sister);
	return 0;
}
