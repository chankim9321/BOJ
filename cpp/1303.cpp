#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define DEBUG_MODE 1

using namespace std;

int visited[100][100] = {0,};
vector<string> field;

pair<int, int> solution(int width, int height){
	pair<int, int> graph;
	pair<int, int> result;
	result.first = 0;
	result.second = 0;
	graph.first = 1;
	graph.second = 1;
	visited[0][0] = 1;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			char pos = field[i][j];
			int flag = 0;
			if(pos == field[i+1][j] && !visited[i+1][j]){ // SOUTH
				visited[i+1][j] = 1;
				flag = 1;
				if(pos == 'W') graph.first++;
				else graph.second++;
			}
			if(pos == field[i-1][j] && !visited[i-1][j]){ // NORTH
				visited[i-1][j] = 1;
				flag = 1;
				if(pos == 'W') graph.first++;
				else graph.second++;
			}
			if(pos == field[i][j+1] && !visited[i][j+1]){ // EAST
				visited[i][j+1] = 1;
				flag = 1;
				if(pos == 'W') graph.first++;
				else graph.second++;
			}
			if(pos == field[i][j-1] && !visited[i][j-1]){ // WEST
				visited[i][j-1] = 1;
				flag = 1;
				if(pos == 'W') graph.first++;
				else graph.second++;
			}
			if(!flag){ // 현재점에서 같은 팀이 근처에 없을 때
				if(pos == 'W') {
					result.first += pow(graph.first,2);
					graph.first = 0;
				}
				else{
					result.second += pow(graph.second,2);
					graph.second = 0;
				}
			}
		}
	}
	return result;
}
int main(int argc, char* argv[]){
	int width, height;
	cin >> height >> width;
	cin.ignore(); // buffer clear

	for(int i=0; i<height; i++){ // init
		string line;
		getline(cin, line);
		field.push_back(line);
	}

	pair<int, int> result = solution(width, height);
	cout << result.first << " " << result.second  << '\n';
	return 0;
}
