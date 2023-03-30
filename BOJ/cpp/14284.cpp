#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> path;
vector<int> dist;
int n,m;
int s,t;
void init(){
	cin >> n >> m;
	path.resize(n+1);
	dist.resize(n+1, 10e8);
	for(int i=0; i<m; i++){
		int from, to, weight;	
		cin >> from >> to >> weight;
		path[from].push_back({to, weight});
		path[to].push_back({from, weight});
	}
	cin >> s >> t;
}
void dijkstra(int start){
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	while(!pq.empty()){
		int current = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if(dist[current] < weight) continue;
		for(int i=0; i<path[current].size(); i++){
			int next = path[current][i].first;
			int nextWeight = path[current][i].second + weight;
			if(dist[next] > nextWeight){
				dist[next] = nextWeight;
				pq.push({-nextWeight, next});
			}
		}
	}
}
void sol(){
	dijkstra(s);
	cout << dist[t] << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	sol();
	return 0;
}
