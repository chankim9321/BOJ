#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define INF 1000000000
using namespace std;


vector<vector<int>> map1(11, vector<int> (11, INF));
vector<vector<int>> map2 = map1;
void init(vector<vector<int>> &map){
	for(int i=1; i<=10; i++){
		map[i][i] = 0;
	}
	map[1][4] = 12; map[4][1] = 12;
	map[1][2] = 15; map[2][1] = 15;
	map[2][3] = 21; map[3][2] = 21;
	map[2][8] = 7; map[8][2] = 7;
	map[3][9] = 25; map[9][3] = 25;
	map[4][5] = 10; map[5][4] = 10;
	map[4][6] = 4; map[6][4] = 4;
	map[5][6] = 3; map[6][5] = 3;
	map[5][8] = 10; map[8][5] = 10;
	map[6][7] = 13; map[7][6] = 13;
	map[7][10] = 15; map[10][7] = 15;
	map[8][9] = 19; map[9][8] = 19;
	map[8][10] = 9; map[10][8] = 9;
	map[9][10] = 5; map[10][9] = 5;
}
vector<int> dijkstra(int start){
	vector<int> dist(11, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	while(!pq.empty()){
		int current = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if(dist[current] < weight) continue;
		for(int i=1; i<=10; i++){
			if(i == current) continue;
			if(map2[current][i] != INF){
				int next = i;	
				int nextWeight = weight + map2[current][i];
				if(dist[next] > nextWeight){
					dist[next] = nextWeight;
					pq.push({-nextWeight, next});
				}
			}
		}
	}
	return dist;
}
void allPairShortestWithDijkstra(){
	init(map2);
	for(int i=1; i<=10; i++){
		map2[i] = dijkstra(i);
	}
}
void floydWarshall(){
	init(map1);
	for(int k=1; k<=10; k++){
		for(int i=1; i<=10; i++){
			for(int j=1; j<=10; j++){
				map1[i][j] = min(map1[i][j], map1[i][k] + map1[k][j]);
			}
		}
	}
}
void printMap(vector<vector<int>> &map){
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			if(map[i][j] == INF) cout << "X ";
			else cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}
int main(int argc, char* argv[]){
	cout << "플로이드 워셜 이용" << '\n';
	floydWarshall();
	printMap(map1);
	cout << "다익스트라 n번 이용" << '\n';
	allPairShortestWithDijkstra();
	printMap(map2);
	return 0;
}
