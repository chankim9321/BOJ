#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<vector<pair<int, int>>> path;
int tracking[201];
int floydPath[201][201];
void init(){
	cin >> n >> m;
	path.resize(n+1);
	fill_n(&floydPath[0][0], 201*201, 10e8);
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from].push_back({to, weight});
		path[to].push_back({from, weight});
		floydPath[from][to] = weight;
		floydPath[to][from] = weight;
	}
}
void dijkstra(int start){
	vector<int> dist;
	dist.resize(n+1, 10e8);
	fill_n(&tracking[0], 201, 0);
	tracking[start] = start;
	priority_queue<pair<int, int>> pq;	
	dist[start] = 0;
	pq.push({0, start});
	while(!pq.empty()){
		int current = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if(dist[current] < weight) continue;
		for(int i=0; i<path[current].size(); i++){
			int next = path[current][i].first;
			int nextWeight = weight + path[current][i].second;
			if(nextWeight < dist[next]){
				dist[next] = nextWeight;
				pq.push({-nextWeight, next});
				tracking[next] = current;
			}
		}
	}
}
void sol(){
	for(int i=1; i<=n; i++){
		dijkstra(i);
		for(int j=1; j<=n; j++){
			int idx = j;
			while(tracking[idx] != i) idx = tracking[idx];
			if(idx == i) cout << "- ";
			else cout << idx << " ";
		}
		cout << '\n';
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	sol();
	return 0;
}
