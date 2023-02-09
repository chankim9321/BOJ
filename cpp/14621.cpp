#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int vert, edge;
vector<char> univState;
vector<pair<int, pair<int, int>>> v;
vector<int> parent;
bool visited[1001];
void init(){
	cin >> vert >> edge;	
	univState.resize(vert+1);
	parent.resize(vert+1);
	fill_n(&visited[0], 1001, false);
	for(int i=1; i<=vert; i++){
		cin >> univState[i];
	}
	for(int i=1; i<=vert; i++){
		parent[i] = i;
	}
	for(int i=0; i<edge; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		v.push_back({weight, {from, to}});
	}
}
int getParent(int node){
	if(parent[node] == node) return node;
	else return parent[node] = getParent(parent[node]);
}
void setUnion(int n1, int n2){
	n1 = getParent(n1);
	n2 = getParent(n2);
	if(n1 > n2) parent[n1] = n2;
	else parent[n2] = n1;
}
bool hasCycle(int n1, int n2){
	n1 = getParent(n1);
	n2 = getParent(n2);
	if(n1 == n2) return true;
	else return false;
}
void kruskal(){
	int result = 0;
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){ // 모든 경로에 대해서
		int from = v[i].second.first;
		int to = v[i].second.second;
		int weight = v[i].first;
		if(!hasCycle(from, to) && univState[from] != univState[to]){ // 사이클 형성을 이루지않고 서로가 다른 집합일 때
			result += weight;
			setUnion(from, to);
			visited[from] = true;
			visited[to] = true;
		}
	}
	for(int i=1; i<=vert; i++){
		if(!visited[i]) {
			cout << -1 << '\n';
			return;
		}
	}
	cout << result << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	kruskal();
	return 0;
}
