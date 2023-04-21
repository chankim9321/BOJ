#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	* 테스트케이스는 다음과 같다
	a b c d e f
	1 2 3 4 5 6

	6 10 // 정점의 갯수, 간선의 수
	3 2 1 // from, to, weight
	3 6 1
	2 6 2
	2 1 3
	2 4 4
	1 5 4
	1 4 2
	4 6 7
	4 5 5
	5 6 9

*/
bool visited[101];
int n, m;
vector<vector<pair<int, int>>> edge;
void init(){
	cin >> n >> m; // 정점의 갯수와 간선의 갯수	
	edge.resize(n+1);	
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		edge[from].push_back({to, weight});
		edge[to].push_back({from, weight});
	}
}
int prim(int start){
	int result = 0;
	fill_n(&visited[0], 101, false); // 방문확인여부 배열 초기화
	priority_queue<pair<int, int>> pq;  // 최소의 비용을 가지는 정점을 찾기위한 힙
	pq.push({0, start});
	while(!pq.empty()){
		int current = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if(visited[current]) continue; // 이미 방문된 정점이라면 pass
		// 방문되지 않은 정점이라면
		visited[current] = true;
		result += weight;
		for(int i=0; i<edge[current].size(); i++){ // 현재점에서 이동가능한 정점중에
			int next = edge[current][i].first;	
			int weight = edge[current][i].second;
			if(!visited[next]){ // 방문되지 않은 정점일 때
				pq.push({-weight, next}); // 힙에 삽입
			}
		}
	}
	return result;
}
int main(int argc, char* argv[]){
	
	init();
	cout << prim(1) << '\n';
	return 0;
}
