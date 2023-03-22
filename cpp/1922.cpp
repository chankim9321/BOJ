#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int vert, edge;
vector<int> parent;
bool sortByWeight(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b){
	return a.second < b.second;
}
vector<pair<pair<int, int>, int>> graph;
int getParent(int node){
	if(parent[node] == node) return node;
	return parent[node] = getParent(parent[node]); // 찾은 다음 돌아올때는 각자의 루트를 저장하게됨(최적화)
}
void unionParent(int n1, int n2){
	n1 = getParent(n1);
	n2 = getParent(n2);
	if(n1 > n2) parent[n1] = n2;
	else parent[n2] = n1;
}
bool hasCycle(int from, int to){
	from = getParent(from);
	to = getParent(to);
	if(from == to) return true;
	else return false;
}
void init(){
	cin >> vert >> edge;
	parent.resize(vert+1);
	for(int i=0; i<parent.size(); i++){
		parent[i] = i;
	}
	for(int i=0; i<edge; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		graph.push_back({{from, to}, weight});
	}
}
int kruskal(){
	int result = 0;
	sort(graph.begin(), graph.end(), sortByWeight);
	for(int i=0; i<graph.size(); i++){
		int from = graph[i].first.first;
		int to = graph[i].first.second;
		int weight = graph[i].second;
		if(!hasCycle(from, to)){
			result += weight;
			unionParent(from, to);
		}
	}
	return result;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	init();	
	cout << kruskal() << '\n';

	return 0;
}
