#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 10e8
using namespace std;

int vertex, edge, destCandidate;
int start, passedFrom, passedTo;

vector<vector<int>> initPath(){
	cin >> vertex >> edge >> destCandidate;
	cin >> start >> passedFrom >> passedTo;
	vector<vector<int>> path(vertex+1, vector<int>(vertex+1, INF));
	for(int i=1; i<=vertex; i++){
		path[i][i] = 0;
	}
	for(int i=0; i<edge; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from][to] = weight;
		path[to][from] = weight;
	}
	return path;
}
vector<int> getShortestPath(int start, vector<vector<int>>& path){
	vector<int> dist(vertex+1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({start,0});
	while(!pq.empty()){
		int current = pq.top().first;
		int currentDist = -pq.top().second;
		pq.pop();
		if(dist[current] < currentDist) continue;
		for(int i=1; i<path[current].size(); i++){
			if(path[current][i] == INF) continue;
			int next = i;
			int nextDist = path[current][i];
			if(dist[next] > currentDist + nextDist){
				dist[next] = currentDist + nextDist;
				pq.push({next, -dist[next]});
			}
		}
	}
	return dist;	
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for(int i=0; i<tc; i++){
		vector<vector<int>> path = initPath();
		vector<int> scFromStart = getShortestPath(start, path); // start 에서부터의 최단경로
		vector<int>	scFromPassedTo = getShortestPath(passedTo, path); // 냄새가 시작되는 곳1
		vector<int>	scFromPassedFrom = getShortestPath(passedFrom, path); // 냄새가 시작되는 곳2

		int scToPassedFrom = scFromStart[passedFrom]; // start 에서 냄새가 시작되는 곳 까지의 거리값1
		int scToPassedTo = scFromStart[passedTo]; // start 에서 냄새가 시작되는 곳 까지의 거리값2
		int passedWeight = path[passedFrom][passedTo]; // 냄새가 나는 거리의 비용
		vector<int> destCd;
		vector<int> result;
		for(int i=0; i<destCandidate; i++){
			int dst;
			cin >> dst;
			destCd.push_back(dst);	
		}
		for(int i=0; i<destCd.size(); i++){
			int dst = destCd[i];
			int finalDestPath = min(scToPassedFrom + passedWeight + scFromPassedTo[dst], scToPassedTo + passedWeight + scFromPassedFrom[dst]);
			if(scFromStart[dst] >= finalDestPath){
				result.push_back(dst);
			}
		}
		sort(result.begin(), result.end());
		for(int i=0; i<result.size(); i++){
			cout << result[i] << " ";
		}
		cout << '\n';
	}
}
