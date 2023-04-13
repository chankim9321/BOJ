#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
vector<vector<pair<int, int>>> edge;
int n, m, s;

/*
	* 테스트 케이스는 다음과 같다.
	서울 원주 강릉 천안 대전 논산 광주 대구 포항 부산
	1	 2	  3	   4	5	 6	  7	   8	9	 10
	10 14 1 // 정점 갯수, 간선갯수, 시작 정점
	1 4 12 // from, to, weight
	1 2 15
	2 3 21
	2 8 7
	3 9 25
	4 5 10
	4 6 4
	5 6 3
	5 8 10
	6 7 13
	7 10 15
	8 9 19
	8 10 9
	9 10 5
*/
void init(){
	cin >> n >> m >> s; // 정점의 갯수, 간선의 갯수, 시작정점을 입력받는다.
	edge.resize(n+1); // 시작정점 편의상 0이 아닌 1부터 설정
	for(int i=0; i<m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		// 양방향 간선으로 가정한다
		edge[from].push_back({to, weight});	
		edge[to].push_back({from, weight});	
	}
}
vector<int> dijkstra(int start){
	vector<int> dist(n+1, INT_MAX); // 거리값은 아직 아무것도 모르므로 int의 최대값으로 설정
	dist[start] = 0; // 시작정점의 비용은 0으로 설정
	priority_queue<pair<int, int>> pq; // 최소의 비용을 가지는 정점만을 반환
	pq.push({0, start});
	while(!pq.empty()){
		int current = pq.top().second;
		int weight = -pq.top().first; // 힙자체는 최대힙이지만 음수로 삽입하고 받으면 최소힙으로 간주
		pq.pop();
		if(dist[current] < weight) continue; // 이미 최소비용이라면 pass
		// 현재 정점으로 부터 이동가능한 정점
		for(int i=0; i<edge[current].size(); i++){
			int next = edge[current][i].first;
			int nextWeight = weight + edge[current][i].second;
			// next로 가는 기존의 비용이 새로 발견된 비용보다 크다면 업데이트
			if(dist[next] > nextWeight){
				dist[next] = nextWeight;
				pq.push({-nextWeight, next}); // 힙에 삽입
			}
		}
	}
	// 갱신된 start로 부터 모든 정점의 최소비용을 가지는 vector를 반환
	return dist;
}
int main(int argc, char* argv[]){
	init();
	vector<int> v = dijkstra(s);
	vector<string> area = {"NOT", "서울", "원주", "강릉", "천안", "대전", "논산", "광주", "대구", "포항", "부산"};
	cout << area[s] << "에서부터 모든 지역의 최소비용은 다음과 같다.\n";
	for(int i=1; i<=n; i++){
		cout <<  area[i] << " 까지 최소비용 = " << v[i] << '\n';
	}
	return 0;
}
