#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<bool> isVisible;
vector<vector<pair<int, int>>> path;
void init(){
	cin >> n >> m;
	path.resize(n);
	isVisible.resize(n, false);
	for(int i=0; i<n; i++){
		int visible;
		cin >> visible;
		if(i == 0 || i == n-1) continue; 
		if(visible) isVisible[i] = true;
	}
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from].push_back({to, weight});
		path[to].push_back({from, weight});
	}
}
int dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	vector<int> dist;
	dist.resize(n, 10e8);
	dist[start] = 0;
	pq.push({0, start});
	while(!pq.empty()){
		int current = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if(dist[current] < weight) continue;
		for(int i=0; i<path[current].size(); i++){
			int next = path[current][i].first;
			int nextWeight = path[current][i].second + weight;
			if(isVisible[next]) continue; // 시야에 보이면 갱신 x
			if(dist[next] > nextWeight){
				dist[next] = nextWeight;
				pq.push({-nextWeight, next});
			}
		}
	}
	return dist[n-1];
}
int main(){
	init();
	int result = dijkstra(0);
	if(result == 10e8) cout << -1 << '\n';
	else cout << result << '\n';
	return 0;
}
