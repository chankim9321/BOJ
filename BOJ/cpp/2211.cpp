#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n,m;
vector<vector<pair<int, int>>> path;
vector<int> dist;
int track[1001];
void init(){
	cin >> n >> m;
	path.resize(n+1);	
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from].push_back({to, weight});
		path[to].push_back({from, weight});
	}
}
void dijkstra(int s){
	dist.resize(n+1, 10e8);	
	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({s, 0});
	while(!pq.empty()){
		int current = pq.top().first;
		int weight = -pq.top().second;
		pq.pop();
		if(dist[current] < weight) continue;
		for(int i=0; i<path[current].size(); i++){
			int next = path[current][i].first;
			int nextWeight = weight + path[current][i].second;
			if(dist[next] > nextWeight){
				dist[next] = nextWeight;
				pq.push({next, -nextWeight});
				track[next] = current;
			}
		}
	}
}
void tracking(){
	cout << n - 1 << '\n';
	for(int k=2; k<=n; k++){
		cout << k << " " << track[k] << '\n';
	}
}
int main(int argc, char* argv[]){
	init();
	dijkstra(1);
	tracking();
}
