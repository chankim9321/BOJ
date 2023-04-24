#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  * 테스트케이스는 다음과 같다
	a b c d e f
	1 2 3 4 5 6

	6 10 // 정점의 수, 간선의 수,
	1 2 8 // from, to, weight
	1 4 2
	1 5 4
	2 4 4
	2 3 1
	2 6 2
	3 6 1
	4 5 3
	4 6 7
	5 6 9
*/
vector<int> parent; // root node check vector
vector<pair<int, pair<int, int>>> edge; // [{weight, {from, to}}]
int n, m; // 노드갯수, 간선 갯수
// disjoint set 
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
// init
void init(){
	cin >> n >> m;
	parent.resize(n+1);
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		edge.push_back({weight, {from, to}});
	}
	for(int i=1; i<=n; i++){ // 각 노드는 자신을 가르킴
		parent[i] = i; 
	}
}
int kruskal(){
	int result = 0;
	sort(edge.begin(), edge.end()); // weight 를 기준으로 오름차순 정렬 // 시간 복잡도는 m log m
	for(int i=0; i<edge.size(); i++){ // 시간 복잡도는 m - 1
		int from = edge[i].second.first;
		int to = edge[i].second.second;
		int weight = edge[i].first;
		// 같은 루트를 가르키지 않는다면 
		// 서로 다른 집합에 속한다는 뜻이므로 사이클을 생성x
		if(getParent(from) != getParent(to)){ 
			setUnion(from, to); // 같은 집합으로 설정
			result += weight;
		}
	}
	return result; // 모든 정점을 잇는 최소비용 반환
}
int main(int argc, char* argv[]){
	init();	
	cout << kruskal() << '\n';
}
