#include <iostream>
#include <vector>
#define INF 10e7

using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin >> n >> k;
	bool visited[11] = {false,};
	vector<vector<int>> planet(n, vector<int> (n,INF));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int fee;
			cin >> fee;
			planet[i][j] = fee;
		}
	}
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(planet[i][j] > planet[i][k] + planet[k][j]){
					planet[i][j] = planet[i][k] + planet[k][j];
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << planet[i][j] << " ";
		}
		cout << '\n';
	}

	int res=0;
	while(!visited[k]){
		visited[k] = true;
		int next;
		int mini = 10000;
		for(int i=0; i<n; i++){
			if(planet[k][i] != 0 && !visited[i]){
				if(planet[k][i] < mini){
					next = i;
					mini = planet[k][i];
				}
			}
		}
		k = next;
		res += mini;
	}
	cout << res-10000 << '\n';
	return 0;
}
