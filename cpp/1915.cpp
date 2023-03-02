#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
vector<vector<int>> v;
int n, m;
int sqSize = 0;

void init(){
	scanf("%d %d",&n, &m);
	v.resize(n, vector<int>(m, -1));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &v[i][j]);
			if(v[i][j] == 1) sqSize = 1;
		}
	}
}
void sol(){
	int answer = 1;
	if(sqSize == 0){
		printf("0\n");
		return;
	}
	while(sqSize < n && sqSize < m){
		bool is_exist = false;
		for(int i = 0; i + sqSize < n; i++){
			for(int j = 0; j + sqSize < m; j++){
				int area = v[i][j];
				if(area == 0) continue;
				if(area != v[i + 1][j]){
					v[i][j] = 0;
					continue;
				}
				if(area != v[i][j + 1]){
					v[i][j] = 0;
					continue;
				}
				if(area != v[i + 1][j + 1]){
					v[i][j] = 0;
					continue;
				}
				// 이후는 각 요소가 1이라는 의미 (정사각형을 이룸)
				is_exist = true;
			}
		}
		if(is_exist) answer++;
		sqSize++;
	}
	printf("%d\n", answer* answer);
}
*/
int main(int argc, char* argv[]){
	
	// 내가 푼 코드
	//init();
	//sol();
	
	// 최적화 코드
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);

	int dp[1001][1001];
	fill_n(&dp[0][0], 1001*1001, 0);
	int r, c;
	cin >> r >> c;
	int area;
	for(int i=1; i<= r; i++){
		string s; 
		cin >> s;
		for(int j=1; j<=c; j++){
			if(s[j-1] == '1') dp[i][j] = min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
			area = max(dp[i][j], area);
		}
	}
	cout << area * area << '\n';
	return 0;
}
