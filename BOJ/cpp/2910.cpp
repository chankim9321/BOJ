#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
	if(a.second.first == b.second.first) return a.second.second < b.second.second;
	return a.second.first > b.second.first;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	cin >> n >> c;
	map<int, pair<int, int>> m;
	int seq = 1;
	for(int i=0; i<n; i++){
		int number;
		cin >> number;
		if(m.find(number) == m.end()){
			m.insert({number,{1, seq++}});
		}
		else m[number].first++;
	}
	vector<pair<int, pair<int, int>>> tmp(m.begin(), m.end());
	sort(tmp.begin(), tmp.end(), cmp);
	for(auto i : tmp){
		for(int k=0; k<i.second.first; k++){
			cout << i.first << " ";
		}
	}
	cout << '\n';
}
