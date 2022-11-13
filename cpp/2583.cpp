#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visited[101][101];

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int height, width, squares;
	cin >> height >> width >> squares;
	for(int i=0; i<squares; i++){
		pair<int, int> start;
		pair<int, int> end;
		cin >> start.first >> start.second >> end.first >> end.second;
		for(int y=start.second; y<end.second; y++){
			for(int x=start.first; x<end.first; x++){
				visited[y][x] = true;
			}
		}
	}
	vector<int> resArea;
	int areaNum=0;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(!visited[i][j]){
				visited[i][j] = true;
				queue<pair<int, int> > q;
				q.push({i,j});
				int cnt=1;
				while(!q.empty()){
					int y= q.front().first;
					int x= q.front().second;
					q.pop();
					for(int k=0; k<4; k++){
						int ny = y+dy[k];
						int nx = x+dx[k];
						if(ny >= 0 && nx >= 0 && ny < height && nx < width){
							if(!visited[ny][nx]){
								visited[ny][nx] = true;
								q.push({ny, nx});
								cnt++;
							}
						}
					}
				}
				areaNum++;
				resArea.push_back(cnt);
			}
		}
	}
	sort(resArea.begin(), resArea.end());
	cout << areaNum << '\n';
	for(int i=0; i<resArea.size(); i++){
		cout << resArea[i] << " ";
	}
	cout << '\n';
	return 0;
}
