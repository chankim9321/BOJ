#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> map = {
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,0,0,0,0,0,1,0},
	{0,1,1,1,1,0,0,0,1,0,0},
	{0,1,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,1,1,0,0},
	{0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,1,1,1,0,1,1},
	{0,0,0,0,1,1,1,1,0,0,0},
	{0,1,1,0,1,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0,0,1,0},
	{0,0,0,0,0,0,1,0,0,0,1},
};
int u[11] = {0,1,2,3,4,5,6,7,8,9,10};
bool visited[11];
pair<int, vector<int>> getMaxSizeVertex(){
	vector<int> res;
	int maxEdges = -1;
	int v = -1;
	for(int i=1; i<=10; i++){
		int edges = 0;
		if(visited[i]) continue; // 이미 방문한 집합이라면 무시
		for(int j=1; j<=10; j++){
			if(!visited[j] && map[i][j]) edges++;
		}
		if(maxEdges < edges) {
			res = map[i];
			maxEdges = edges;
			v = i;
		}
	}
	return {v, res}; 
}
int main(int argc, char* argv[]){
	vector<int> a;
	vector<int> minimumVert;
	while(a.size() < 10){ // O(n)
		pair<int, vector<int>> maxVertex = getMaxSizeVertex(); // O(n^2)
		minimumVert.push_back(maxVertex.first);
		vector<int> vertexSet = maxVertex.second;
		cout << "선택된 정점: " << maxVertex.first << '\n';
		for(int i=1; i<vertexSet.size(); i++){
			if(vertexSet[i] && !visited[i]){
				cout << "인접 정점: " << i << '\n';
			}
		}
		cout << "------------" << '\n';
		for(int i=1; i<vertexSet.size(); i++){
			if(vertexSet[i] && !visited[i]){
				a.push_back(i);
				visited[i] = true;
			}
		}
	}
	cout << "결과" << '\n';
	sort(a.begin(), a.end());
	for(const auto vert : a){
		cout << "집합 a 의 원소 = " << vert << '\n';
	}
	cout << "선택된 최소의 정점 개수 = " << minimumVert.size() << '\n';
	for(const auto vert : minimumVert){
		cout << "선택된 정점 = " << vert << '\n';
	}
	return 0;
}
