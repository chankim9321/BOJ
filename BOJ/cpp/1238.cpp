#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 10e8
using namespace std;

int n, m, dest;
vector<pair<int, int>> pathEdge[1001];
vector<pair<int, int>> revsEdge[1001];
int* getShortestPath(int start, vector<pair<int, int>> edge[] ){
	int* dist = new int[n+1];
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
	return dist;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> dest;
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		pathEdge[from].push_back({to, weight});
		revsEdge[to].push_back({from, weight});
	}
	int* pathToDest = getShortestPath(dest, revsEdge);
	int* pathFromDest = getShortestPath(dest, pathEdge);

	int res = 0;
	for(int i=1; i<=n; i++){
		res = max(res, pathToDest[i] + pathFromDest[i]);
	}
	cout << res << '\n';
	return 0;
}
