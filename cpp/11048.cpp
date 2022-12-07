#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;	
	int map[n+1][m+1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> map[i][j];
			if(j == 1 && i != 1){
				map[i][j] += map[i-1][j];
			}
			if(i == 1 && j != 1){
				map[i][j] += map[i][j-1];
			}
		}
	}
	for(int i=2; i<=n; i++){
		for(int j=2; j<=m; j++){
			map[i][j] += max(max(map[i-1][j], map[i][j-1]), map[i-1][j-1]);
		}
	}
	cout << map[n][m] << '\n';
	return 0;
}
