#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define INF 10e14
using namespace std;


int n, m, start, dst;
ll getShortestPath(vector<pair<int, int>> edge[]){
	ll path[n+1];
	fill_n(&path[0], n+1, INF);
	priority_queue<pair<int, int>> pq;
	path[start] = 0;
	pq.push({start, 0});
	while(!pq.empty()){
		int present = pq.top().first;
		ll distance = -pq.top().second;
		pq.pop();
		if(distance > path[present]) continue;
		for(int i=0; i<edge[present].size(); i++){
			int next = edge[present][i].first;
			ll nextDistance = edge[present][i].second + distance;
			if(nextDistance < path[next]){
				path[next] = nextDistance;
				pq.push({next, -nextDistance});
			}
		}
	}
	return path[dst];
}
int main(int argc, char* argv[]){
	cin >> n >> m;
	vector<pair<int, int>> edge[n+1];	
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		edge[from].push_back({to, weight});
	}
	cin >> start >> dst;	
	cout << getShortestPath(edge) << '\n';
	return 0;
}
