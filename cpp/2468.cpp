#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101];
int surface[101][101];
bool visited[101][101] = {{false,},};
int N;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0 j<N; j++){
			cin >> map[i][j];
		}
	}
}
void sol(){
	int res=0;
	for(int k=1; k<101; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				surface[i][j]++;
				if(surface[i][j] >= map[i][j]){
					visited[i][j] = true;
				}
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				int queue<pair<int,int>> q;
				if(!visited[i][j]){
						
				}
			}
		}
	}
	
}
int main(int argc; char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fill_n(&surface[0][0], 101*101, 0);	
	input();
	sol();
	return 0;
}

