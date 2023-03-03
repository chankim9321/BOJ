#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX_HEIGHT 2*10e8+1
using namespace std;

int n, m;
int minHeight = MAX_HEIGHT, maxHeight = -1;
vector<int> trees;
void init(){
	cin >> n >> m;
	trees.resize(n);
	for(int i=0; i<n; i++){
		cin >> trees[i];
		minHeight = min(trees[i], minHeight);	
		maxHeight = max(trees[i], maxHeight);
	}
}
void sol(){
	ll answer = 0;
	ll diff = MAX_HEIGHT;
	while(minHeight < maxHeight){
		ll sawHeight = (minHeight + maxHeight)/2;
		ll timbers = 0;
		for(int i=0; i<trees.size(); i++){
			if(sawHeight < trees[i]){
				timbers += trees[i] - sawHeight;
			}
		}
		if(timbers > m){ // 자른 목재가 요구사항보다 많을 때
			minHeight = sawHeight + 1;
			if(diff > timbers - m){
				diff = timbers - m;
				answer = sawHeight;
			}
		}
		else if(timbers < m){
			maxHeight = sawHeight;
		}
		else{
			answer = sawHeight;
			break;
		}
	}
	cout << answer << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	sol();
	return 0;
}
