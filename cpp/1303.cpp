#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define DEBUG_MODE 1

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visited[103][103] = {0,};
vector<string> field;

int bfs(int x, int y){ 
	int result=1;
	queue<pair<int, int> > q;
	visited[x][y] = 1;
	char team = field[x][y];
	q.push(make_pair(x,y));
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int X = x + dx[i];
			int Y = y + dy[i];	
			if(!visited[X][Y] && field[X][Y] == team){
				visited[X][Y] = 1;
				q.push(make_pair(X, Y));
				result++;
			}
		}
	}
	return result*result;
}
pair<int, int> solution(int width, int height){
	pair<int, int> result;
	result.first = 0;
	result.second = 0;
	for(int i=1; i<height+1; i++){
		for(int j=1; j<width+1; j++){
			if(!visited[i][j]){
				if(field[i][j] == 'W') result.first += bfs(i,j);
				if(field[i][j] == 'B') result.second += bfs(i,j);
			}
		}
	}
	return result;
}
string getEmptyStr(int size){
	string empty;
	for(int i=0; i<size; i++){
		empty.append("E");
	}
	return empty;
}

int main(int argc, char* argv[]){
	int width, height;
	cin >> height >> width;
	cin.ignore(); // buffer clear
	
	field.push_back(getEmptyStr(width+2));	
	for(int i=0; i<height; i++){ // init
		string line;
		getline(cin, line);
		line.insert(0,"E");
		line.append("E");
		field.push_back(line);
	}
	field.push_back(getEmptyStr(width+2));	

	pair<int, int> result = solution(width, height);
	cout << result.first << " " << result.second << '\n';
	return 0;
}
