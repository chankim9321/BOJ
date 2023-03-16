#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VALUE 1000000
using namespace std;

int peopleLimit, cities;
vector<pair<int, int>> li;
vector<int> cache;
void init(){
	cin >> peopleLimit >> cities;
	cache.resize(MAX_VALUE, 0);
	for(int i=0; i<cities; i++){
		int fee, people;
		cin >> fee >> people;
		li.push_back({fee, people});
	}
}
void sol(){
	for(int i=0; i<li.size(); i++){
		// 하나의 홍보방식이 추가될 떄 마다 최적화
		int fee = li[i].first;
		int people = li[i].second;
		cache[fee] = people;
		cache[0] = 0;
		for(int j = fee; j < MAX_VALUE; j++){
			cache[j] = max(cache[j] , people + cache[j - fee]);
		}
	}
	for(int i=0; i<MAX_VALUE; i++){
		if(cache[i] >= peopleLimit){
			cout << i << '\n';
			break;
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);
	
	init();
	sol();
	return 0;
}
