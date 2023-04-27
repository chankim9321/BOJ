#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
int n,m,w;
bool BellmanFord(vector<vector<pair<int, int>>>& edge, int start){
	vector<int> dist(n+1, 10e8);
	dist[start] = 0;
	int tmp;
	for(int i=1; i<=n; i++){ // 모든 노드
		for(int j=0; j<edge[i].size(); j++){ // 모든 간선
			int current = i;
			int next = edge[i][j].first;
			int weight = edge[i][j].second;
			if(dist[current] == 10e8) continue;
			if(dist[next] > dist[current] + weight) dist[next] = dist[current] + weight;
		}
	}
	tmp = dist[start];
	for(int i=1; i<=n; i++){ // 모든 노드
		for(int j=0; j<edge[i].size(); j++){ // 모든 간선
			int current = i;
			int next = edge[i][j].first;
			int weight = edge[i][j].second;
			if(dist[current] == 10e8) continue;
			if(dist[next] > dist[current] + weight) dist[next] = dist[current] + weight;
		}
	}
	if(dist[start] != tmp) return true;
	return false;
}
void sol(){
	cin >> tc;
	for(int i=0; i<tc; i++){
		vector<vector<pair<int, int>>> edge;
		cin >> n >> m >> w;
		edge.resize(n+1);
		for(int j=0; j<m; j++){
			int from, to, weight;
			cin >> from >> to >> weight;
			edge[from].push_back({to, weight});
			edge[to].push_back({from, weight});
		}
		int start;
		for(int j=0; j<w; j++){
			int from, to, weight;
			cin >> from >> to >> weight;
			edge[from].push_back({to, -weight});
			start = to;
		}
		if(BellmanFord(edge, start)) cout << "YES" << '\n'; // 음수 사이클이 존재한다면
		else cout << "NO" << '\n';
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sol();
	return 0;
}
