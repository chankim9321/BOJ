#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> parent;
vector<pair<int, int>> syn;
int synapse, neuron;
bool cmp(pair<int, int>& syn1, pair<int, int>& syn2){
	int small1 = min(syn1.first, syn1.second);
	int small2 = min(syn2.first, syn2.second);
	return small1 < small2;
}
int find(int node){
	if(parent[node] == node) return node;
	else return parent[node] = find(parent[node]);
}
void setUnion(int n1, int n2){
	n1 = find(n1);
	n2 = find(n2);
	if(n1 > n2) parent[n1] = n2;
	else parent[n2] = n1;
}
void init(){
	cin >> neuron >> synapse;
	parent.resize(neuron + 1);
	for(int i=1; i<=neuron; i++) parent[i] = i;
	for(int i=0; i<synapse; i++){
		int n1, n2;
		cin >> n1 >> n2;
		syn.push_back({n1, n2});	
	}
}
void sol(){
	int root = 1;
	int answer = 0;
	set<int> s;	
	sort(syn.begin(), syn.end(), cmp);
	for(int i=0; i<synapse; i++){
		setUnion(syn[i].first, syn[i].second);
		s.insert(parent[syn[i].first]);
	}	
	cout << s.size()-1 << '\n';
}
int main(int argc, char* argv[]){
	fastIO;	
	init();
	sol();
	return 0;
}
