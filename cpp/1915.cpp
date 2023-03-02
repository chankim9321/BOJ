#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int n, m;
int sqSize = 0;

void init(){
	cin >> n >> m;	
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
		cout << 0 << '\n';
		return;
	}
	while(sqSize < n && sqSize < m){
		bool is_exist = false;
		for(int i = 0; i + sqSize < n; i++){
			for(int j = 0; j + sqSize < m; j++){
				int area = v[i][j];
				if(area == 0) continue;
				if(area != v[i + sqSize][j]){
					v[i][j] = 0;
					continue;
				}
				if(area != v[i][j + sqSize]){
					v[i][j] = 0;
					continue;
				}
				if(area != v[i + sqSize][j + sqSize]){
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
	cout << answer * answer << '\n';
}
int main(int argc, char* argv[]){
	
	init();
	sol();

	return 0;
}
