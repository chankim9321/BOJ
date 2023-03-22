#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;

int n,m,r;

void floyed_Warshall(vector<vector<int>> &path){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(path[i][j] > path[i][k] + path[k][j]){
					path[i][j] = path[i][k] + path[k][j];
				}
			}
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);
	
	// 지역의 갯수, 수색범위, 경로의 갯수
	cin >> n >> m >> r;	
	vector<int> item(n+1, 0);
	vector<vector<int>> path(n+1, vector<int>(n+1,INF));
	for(int i=1; i<=n; i++){
		int items;
		cin >> items;
		item[i] = items;
	}
	// 경로 설정
	for(int i=0; i<r; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path[from][to] = weight;
		path[to][from] = weight;
	}
	for(int i=1; i<=n; i++){
		path[i][i] = 0;
	}
	floyed_Warshall(path);
	int ans=0;
	for(int start=1; start<=n; start++){
		int maxItem = 0;
		for(int i=1; i<=n; i++){
			if(path[start][i] <= m){
				maxItem += item[i];
			}
		}
		ans = max(ans, maxItem);
	}
	cout << ans << '\n';
	return 0;
}
