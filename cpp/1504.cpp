#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 10e9
using namespace std;

int v, e;
int getShortestPath(int start, int end, vector<pair<int, int>> path[]){
	int *dist = new int[v+1];
	fill_n(&dist[0], v+1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({start, 0});
	while(!pq.empty()){
		int current = pq.top().first;
		int currentDist = -pq.top().second;
		pq.pop();
		for(int i=0; i<path[current].size(); i++){
			int next = path[current][i].first;
			int nextDist = currentDist + path[current][i].second;
			if(dist[next] > nextDist){
				dist[next] = nextDist;
				pq.push({next, -nextDist});
			}
		}
	}
	int result = dist[end];
	delete[] dist;
	return result;
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
	int toV1 = getShortestPath(1, v1, path);
	int toV2 = getShortestPath(v1, v2, path);
	int toEnd = getShortestPath(v2, v, path);
	cout << toV1 + toV2 + toEnd << '\n';
	return 0;
}
