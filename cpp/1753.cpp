#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 99999
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int vertex, edge, weight, start;
	cin >> vertex >> edge;	
	vector<pair<int, int> > memory[vertex+1];
	cin >> start;
	for(int i=1; i<=edge; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		memory[from].push_back(make_pair(weight, to));
	}

	int d[vertex+1]; 
	for(int i=1; i<=vertex; i++){
		d[i] = INF;
	}
	
	// dijkstra start
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // 상태는 최대 힙
	pq.push(make_pair(0, start));
	while(!pq.empty()){
		int current = pq.top().second; // 현재정점으로부터 최소비용을 가지는 정점의 인덱스 이는 곧 다음 방문할 점.
		int distance = -pq.top().first;  // 가중치에 -를 붙이면 최대의 값은 가장 하위트리쪽으로 빠지면서 최소 힙으로 변환이 가능하다.
		pq.pop();
		if(d[current] < distance) continue;
		for(int i=0; i < memory[current].size(); i++){ // 현재 정점에서 이동가능한 모든 정점을 검사
			// 선택된 노드의 인접 노드
			int next = memory[current][i].second;
			// 선택된 노드를 거쳐서 인접노드로 가는 비용
			int nextDistance = distance + memory[current][i].first;
			if(nextDistance < d[next]){
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
	// update end 
	for(int i=1; i<=vertex; i++){
		if(d[i] == INF){
			cout << "INF" << '\n';
		}
		else cout << d[i] << '\n';
	}
	return 0;
}
