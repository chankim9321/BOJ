#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vert, edge,	addWeight;
vector<pair<int, pair<int, int>>> v;
vector<int> parent;
void init(){
	cin >> vert >> edge >> addWeight;	
	parent.resize(vert+1);
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
	sort(v.begin(), v.end());
	int weightSum = 0;
	int additionalFee = 0;
	for(int i=0; i<v.size(); i++){
		int from = v[i].second.first;
		int to = v[i].second.second;
		int weight = v[i].first;
		if(!hasCycle(from, to)){
			setUnion(from, to);
			weightSum += weight + additionalFee;
			additionalFee += addWeight;
		}
	}
	cout << weightSum << '\n';
	return;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();	
	kruskal();
	return 0;
}
