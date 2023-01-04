#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 10e8
using namespace std;

int v, e;
int* getShortestPath(int start, vector<pair<int, int>> path[]){
	int *dist = new int[v+1];
	for(int i=1; i<=v; i++){
		dist[i] = INF;
	}
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({start, 0});
	while(!pq.empty()){
		int current = pq.top().first;
		int currentDist = -pq.top().second;
		pq.pop();
		if(dist[current] < currentDist) continue;
		for(int i=0; i<path[current].size(); i++){
			int next = path[current][i].first;
			int nextDist = currentDist + path[current][i].second;
			if(dist[next] > nextDist){
				dist[next] = nextDist;
				pq.push({next, -nextDist});
			}
		}
	}
	return dist;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v1, v2;
	cin >> v >> e;
	vector<pair<int, int>> path[v+1];
	for(int i=0; i<e; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from].push_back({to, weight});
		path[to].push_back({from, weight});
	}
	cin >> v1 >> v2;
	int* path1 = getShortestPath(1, path);
	int* path2_1 = getShortestPath(v1, path);
	int* path2_2 = getShortestPath(v2, path);
	int result = min(path1[v1] + path2_1[v2] + path2_2[v], path1[v2] + path2_2[v1] + path2_1[v]);
	if(result >= INF || result < 0) cout << -1 << '\n'; // 오버플로우 발생한 경우
	else cout << result << '\n';
	return 0;
}
