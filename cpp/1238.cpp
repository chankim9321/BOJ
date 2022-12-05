#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 10e8
using namespace std;


int n, m, dest;
vector<pair<int, int>> edge[1001];
int getShortestPath(int start, int dst){
	int dist[n+1];	
	fill_n(&dist[0], n+1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({start, 0});
	while(!pq.empty()){
		int present = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if(dist[present] < distance) continue;
		for(int i=0; i<edge[present].size(); i++){
			int next = edge[present][i].first;
			int nextDist = distance + edge[present][i].second;
			if(nextDist < dist[next]){
				dist[next] = nextDist;
				pq.push({next, -nextDist});
			}
		}
	}
	return dist[dst];
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> dest;
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		edge[from].push_back({to, weight});
	}
	int pathToDest[n+1];
	for(int i=1; i<=n; i++){
		if(i == dest){
			pathToDest[i] = 0;
		}
		else pathToDest[i] = getShortestPath(i, dest);
	}
	int pathFromDest[n+1];
	for(int i=1; i<=n; i++){
		if(i == dest){
			pathFromDest[i] = 0;	
		}
		else pathFromDest[i] = getShortestPath(dest, i);	
	}
		int res = -1;
	for(int i=1; i<=n; i++){
		res = max(res, pathToDest[i] + pathFromDest[i]);
	}
	cout << res << '\n';
	return 0;
}
