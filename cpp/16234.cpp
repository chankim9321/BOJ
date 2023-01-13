#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int mapSize, L, R;
bool visited[51][51];

bool bfs(vector<vector<int>> &map, int posY, int posX){
	queue<pair<int, int>> q;
	visited[posY][posX] = true;	
	q.push({posY, posX});
	int acValue = map[posY][posX];
	vector<pair<int, int>> modified;
	modified.push_back({posY, posX});
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= mapSize || nx >= mapSize || nx < 0 || ny < 0) continue;
			if(visited[ny][nx]) continue;
			int populationGab = abs(map[y][x] - map[ny][nx]);
			if(populationGab >= L && populationGab <= R){
				visited[ny][nx] = true;		
				acValue += map[ny][nx];
				modified.push_back({ny,nx});
				q.push({ny,nx});
			}
		}
	}
	if(acValue == map[posY][posX]) return false;
	else {
		int finalPopul = acValue / modified.size();
		for(const auto i : modified){
			map[i.first][i.second] = finalPopul;
		}
		return true;
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);
	
	// init
	cin >> mapSize >> L >> R;
	vector<vector<int>> map(mapSize, vector<int>(mapSize, 0));
	for(int i=0; i<mapSize; i++){
		for(int j=0; j<mapSize; j++){
			int value;
			cin >> value;
			map[i][j] = value;
		}
	}
	//solution
	int days = 0;
	while(1){
		bool changed = false;
		fill_n(&visited[0][0], 51*51, false);
		for(int i=0; i<mapSize; i++){
			for(int j=0; j<mapSize; j++){
				if(!visited[i][j]){
					if(bfs(map,i,j)){
						changed = true;
					}
					else visited[i][j] = false;
				}
			}
		}
		if(!changed) break;
		else days++;
		/*
		for(int i=0; i<mapSize; i++){
			for(int j=0; j<mapSize; j++){
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}
		cout << "-----------------------" << '\n';
		*/
	}
	cout << days << '\n';
	return 0;
}
