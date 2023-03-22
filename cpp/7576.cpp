#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define DEBUG_MODE 0
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(int argc, char* argv[]){
	int width, height;
	cin >> width >> height;
	int arr[height+2][width+2];
	fill_n(&arr[0][0], (width+2)*(height+2), -1);
		
	queue<pair<int, int> > q;
	for(int i=1; i<height+1; i++){
		for(int j=1; j<width+1; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1) q.push(make_pair(i,j));
		}
	}
	#if DEBUG_MODE
	for(int i=0; i<height+2; i++){
		for(int j=0; j<width+2; j++){
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	#endif
	int cnt = q.size();
	int days = 0;
	while(!q.empty()){
		pair<int, int> co = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int next_x = co.second + dx[i];
			int next_y = co.first + dy[i];
			if(arr[next_y][next_x] == 0){
				arr[next_y][next_x] = 1;
				q.push(make_pair(next_y, next_x));
			}
		}
		cnt--;
		if(cnt == 0){
			days++;
			cnt = q.size();
		}
	}
	bool is_impossible = false;
	for(int i=1; i<height+1; i++){
		for(int j=1; j<width+1; j++){
			if(arr[i][j] == 0){
				is_impossible = true;
			}
		}
	}
	if(is_impossible) cout << -1 << '\n';
	else cout << days-1 << '\n';
	return 0;
}
