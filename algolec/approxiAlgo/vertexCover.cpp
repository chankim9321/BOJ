#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX_VERT 10
using namespace std;

int fullVert = 8; // 목표 커버 수
vector<vector<bool>> edges;
bool visited[MAX_VERT+1];
void init(){
	fill_n(&visited[0], MAX_VERT+1, false);
	edges.resize(MAX_VERT+1);
	for(int i=0; i<=MAX_VERT; i++){
		edges[i].resize(MAX_VERT+1, false);
	}
	// from 1
	edges[1][2] = true;
	edges[1][4] = true;
	edges[1][5] = true;
	edges[1][6] = true;
	edges[1][7] = true;
	edges[1][8] = true;
	// from 2
	edges[2][1] = true;
	edges[2][5] = true;
	// from 3
	edges[3][5] = true;
	edges[3][6] = true;
	// from 4
	edges[4][1] = true;
	edges[4][5] = true;
	edges[4][6] = true;
	// from 5
	edges[5][1] = true;
	edges[5][2] = true;
	edges[5][3] = true;
	edges[5][4] = true;
	edges[5][6] = true;
	edges[5][7] = true;
	// from 6
	edges[6][1] = true;
	edges[6][3] = true;
	edges[6][4] = true;
	edges[6][5] = true;
	edges[6][7] = true;
	edges[6][8] = true;
	// from 7
	edges[7][1] = true;
	edges[7][5] = true;
	edges[7][6] = true;
	// from 8
	edges[8][1] = true;
	edges[8][6] = true;
}
void updateVertSet(pair<int, int> edge, set<int>& vertSet){
	int from = edge.first;
	int to = edge.second;
	vertSet.insert(from);
	vertSet.insert(to);
	visited[from] = true;
	visited[to] = true;
	for(int i=1; i<=fullVert; i++){
		if(edges[from][i] == true){
			edges[from][i] = false;
			vertSet.insert(i);
			visited[i] = true;
		}
	}
	for(int i=1; i<=fullVert; i++){
		if(edges[to][i] == true){
			edges[to][i] = false;
			vertSet.insert(i);
			visited[i] = true;
		}
	}
}
pair<int, int> getArbitraryEdge(){ // 임의의 선분을 반환하는 함수
	int v;
	for(int i=1; i<=fullVert; i++){
		if(!visited[i]){ // 방문하지 않은 정점 중에서
			v = i;
			break;
		}
	}
	for(int i=1; i<=fullVert; i++){
		if(edges[v][i] == true){
			return {v, i};
		}
	}
	return {0,0};
}
int main(int argc, char* argv[]){
	init();
	set<pair<int, int>> edgeSet; 
	set<int> vertSet;
	
	cout << "알고리즘 시작" << '\n';
	pair<int, int> startEdge = {1,2}; // 시작 선분
	edgeSet.insert(startEdge);
	updateVertSet(startEdge, vertSet);
	cout << "현재 정점 집합의 갯수: " << vertSet.size() << '\n';	
	while(vertSet.size() < fullVert){ // 목표 정점개수를 커버 할 때 까지
		pair<int, int> nextEdge = getArbitraryEdge();
		if(nextEdge.first == 0 && nextEdge.second == 0) {
			cout << "오류) getArbitraryEdge() here!" << '\n';
			break;
		}
		edgeSet.insert(nextEdge);
		updateVertSet(nextEdge, vertSet);
		cout << "현재 정점 집합의 갯수: " << vertSet.size() << '\n';	
	}
	cout << " -------- Result --------- " << '\n';
	cout << " 모든 정점을 커버하는 간선은 다음과 같다. " << '\n';
	set<pair<int, int>>::iterator iter;
	for(iter = edgeSet.begin(); iter != edgeSet.end(); iter++){
		cout << "(" << iter->first << ", " << iter->second << ")" << '\n';
	}
	return 0;
}
