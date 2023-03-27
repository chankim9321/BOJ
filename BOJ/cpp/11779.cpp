#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 10e8
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n, m;
int start, dest;
vector<int> dist;
vector<vector<pair<int, int>>> path;
bool flag = false;
void init(){
	cin >> n >> m;
	path.resize(n+1);
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from].push_back({to, weight});
	}
	cin >> start >> dest;
}
void tracking(int s, int sum, vector<int> road){
	if(flag) return;
	if(sum > dist[dest]) return;
	if(sum == dist[dest] && s == dest){
		flag = true;
		// 결과 출력
		cout << dist[dest] << '\n';
		cout << road.size() << '\n';
		for(auto node : road){
			cout << node << " ";
		}
		cout << '\n';
		return;
	}
	for(int i=0; i<path[s].size(); i++){
		road.push_back(path[s][i].first);
		tracking(path[s][i].first, sum + path[s][i].second, road);
		road.pop_back();
	}
}
void dijkstra(int s){
	priority_queue<pair<int, int>> pq;
	dist.resize(n+1, INF);
	dist[s] = 0;
	pq.push({start, 0});
	while(!pq.empty()){
		int current = pq.top().first;
		int weight = -pq.top().second;
		pq.pop();
		for(int i=0; i<path[current].size(); i++){
			int next = path[current][i].first;
			int nextWeight = weight + path[current][i].second;
			if(nextWeight < dist[next]){
				dist[next] = nextWeight;
				pq.push({next, -nextWeight});
			}
		}
	}
}
int main(int argc, char* argv[]){
	fastio;	
	init();
	dijkstra(start);
	vector<int> road;
	road.push_back(start);
	tracking(start, 0, road);
	return 0;
}
