#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999
#define MAX 20001
using namespace std;

int memory[MAX][MAX];
int visited[MAX];

int getSmallerIdx(int dist[], int vertex){
	int min = INF;
	int res = 0;
	for(int i=1; i<=vertex; i++){
		if(min > dist[i] && !visited[i]){
			min = dist[i];
			res = i;
		}
	}
	return res;
}
void dijkstra(int start, int vertex, int dist[]){	
	for(int i=1; i<=vertex; i++){
		dist[i] = memory[start][i]; // 현재정점으로 부터 다른 정점까지의 거리
	}
	visited[start] = 1;
	for(int i=1; i<=vertex-1; i++){
		int current = getSmallerIdx(dist, vertex); // 현재정점으로부터 최소비용을 가지는 정점의 인덱스 이는 곧 다음 방문할 점.
		visited[current] = 1; // 방문 표시
		for(int j=1; j<=vertex; j++){ // 방문한 정점에서 모든 정점
			if(!visited[j]){ // 방문하지 않은 정점들에 한에 
				if(dist[current] + memory[current][j] < dist[j]){ // 이전 정점의 비용 + 현재 정점에서 j로 가는 비용이 이전정점에서 J로 가는 비용으보다 작다면
					dist[j] = dist[current] + memory[current][j]; // 최소비용으로 업데이트 한다.
				}
			}
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fill(&memory[0][0], &memory[MAX][MAX], INF);
	fill(&visited[0], &visited[MAX], 0);
	int vertex, edge, start;
	cin >> vertex >> edge;	
	int dist[vertex+1];
	cin >> start;
	for(int i=1; i<=edge; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		memory[from][from] = 0;
		memory[to][to] = 0;
		memory[from][to] = weight;
	}
	dijkstra(start, vertex, dist);
	for(int i=1; i<=vertex; i++){
		if(dist[i] == INF){
			cout << "INF" << '\n';
		}
		else cout << dist[i] << '\n';
	}
	return 0;
}
