#include <iostream>
#include <algorithm>
#include <vector>
#define INF 10e7
#define DEBUG_MODE 0
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin >> n >> k;
	vector<int> p;
	vector<vector<int>> planet(n, vector<int> (n,INF));
	for(int i=0; i<n; i++){
		if(i != k){
			p.push_back(i);
		}
		for(int j=0; j<n; j++){
			int fee;
			cin >> fee;
			planet[i][j] = fee;
		}
	}
	// 플로이드 워셜 알고리즘
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(planet[i][j] > planet[i][k] + planet[k][j]){
					planet[i][j] = planet[i][k] + planet[k][j];
				}
			}
		}
	}
	#ifndef DEBUG_MODE
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << planet[i][j] << " ";
		}
		cout << '\n';
	}
	#endif
	int res = 10e8;
	do{
		int s = k;
		int fare=0;
		for(auto it = p.begin(); it != p.end(); it++){
			fare += planet[s][*it];
			s = *it;
		}
		res = min(res, fare);
	}while(next_permutation(p.begin(), p.end()));
	cout << res << '\n';
	return 0;
}
