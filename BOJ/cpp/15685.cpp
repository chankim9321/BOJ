#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

bool visited[101][101];
vector<tuple<int, int, int, int>> v;
void init(){
	int c;
	cin >> c;
	for(int i=0; i<c; i++){
		int x,y,d,g;
		cin >> x >> y >> d >> g;
		v.push_back(make_tuple(x,y,d,g));
	}
	fill_n(&visited[0][0], 101*101, false);
}
void setDirection(int &x, int &y, int dir){
	switch(dir){
		case 0:
			visited[y][++x] = true;
			break;
		case 1:
			visited[--y][x] = true;
			break;
		case 2:
			visited[y][--x] = true;
			break;
		case 3:
			visited[++y][x] = true;
			break;
	}
}
int getSquareNumber(){
	int ans = 0;
	for(int i=0; i<101; i++){
		for(int j=0; j<100; j++){
			if(visited[i][j] && visited[i][j+1] && visited[i+1][j] && visited[i+1][j+1]){
				ans++;	
			}
		}
	}
	return ans;
}
void sol(){
	for(int i=0; i<v.size(); i++){
		queue<pair<int, int>> q;
		int x = get<0>(v[i]);
		int y = get<1>(v[i]);
		int dir = get<2>(v[i]);
		int g = get<3>(v[i]);
		visited[y][x] = true;
		vector<int> v; // 간선 방향을 안내하는 벡터
		v.push_back(dir);
		for(int k=1; k<=g; k++){
			queue<int> q;
			for(int j=v.size() - 1; j>=0; j--){
				q.push((v[j] + 1) % 4);	
			}
			while(!q.empty()){
				v.push_back(q.front());
				q.pop();
			}
		}
		for(int k=0; k<v.size(); k++){
			setDirection(x, y, v[k]);
		}
	}
	cout << getSquareNumber() << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	sol();
	return 0;
}
