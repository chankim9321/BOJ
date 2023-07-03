#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edge;
int parent[1001];
void init(){
	scanf("%d %d", &n, &m);
	for(int k=0; k<=n; k++) parent[k] = k;
	int i;
	for(i=1; i<=n; i++){
		int from, to;
		scanf("%d %d", &from, &to);
		edge.push_back({i, {from, to}});
		edge.push_back({i, {to, from}});
	}
	for(int j=0; j<m; j++){
		int from, to;
		scanf("%d %d", &from, &to);
		setUnion(from, to);
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
int main(int argc, char* argv[]){
	init();	
	double sumWeight = 0;
	for(int i=0; i<edge.size(); i++){
		int from = edge[i].second.first;
		int to = edge[i].second.second;
		int weight = edge[i].first;
		if(getParent(n1) != getParent(n2)){
			setUnion(n1, n2);
			sumWeight += weight;
		}
	}
	printf("%.2f\n", sumWeight);
}
