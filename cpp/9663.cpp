#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int vx[16], vy[16];
int dfs(int y, int x){
	for(int i=0; i<y; i++){
		if(y == vy[i]) return 0;
		if(x == vx[i]) return 0;
		if(abs(x - vx[i]) == abs(y - vy[i])) return 0;
	}
	if(y == n-1) {
		return 1;
	}
	vy[y] = y, vx[y] = x;

	int cnt = 0;
	for(int i=0; i<n; i++){
		cnt += dfs(y+1, i);
	}
	return cnt;
}
int main(int argc, char *argv[]){
	cin >> n;
	fill_n(vx, 16, -1);
	fill_n(vy, 16, -1);
	int cnt = 0;
	for(int i=0; i<n; i++){
		cnt += dfs(0,i);
	}
	cout << cnt << '\n';
	return 0;
}
