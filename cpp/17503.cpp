#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define DEBUG_MODE 0
using namespace std;

int N, M, K;
int solution(vector<pair<int, int> >&v){
	int start = 0; // 시작인덱스 ex) 0
	int end = v.size()-1; // 끝 인덱스 ex) 4
	int lastPreferCount;
	int preferCount=0;
	int degreeLevel=0;
	while(start <= end){
		int mid = (start + end)/2; // 중간 인덱스 ex) 2
		//cout << "산정된 인덱스값 = " << mid <<  ", 해당 인덱스값에 존재하는 도수레벨 = " << v[mid].second << '\n';
		priority_queue<pair<int, int> > max_heap;
		for(int i=0; i<= mid; i++){ 
			max_heap.push(v[i]); // 선정된 인덱스 아래로 모든 데이터를 삽입
		}
		for(int i=0; i<N; i++){
			preferCount += max_heap.top().first;
			max_heap.pop();
		}
		//cout << "산정된 선호도의 합 = " << preferCount << '\n';
		if(preferCount >= M){ // 선호도의 합이 요구하는 총합 선호도보다 높을 때는 레벨을 줄일 필요가 있다.
			end = mid-1;
			degreeLevel = v[mid].second; // 현재 도수레벨 기록
		}
		else if(preferCount < M){ // 선호도의 합이 요구하는 총합 선호도보다 낮을 떄는 레벨을 올릴 필요가 있다.
			start = mid+1; 
		}
		lastPreferCount = preferCount;
		preferCount = 0; // 재 초기화
	}
	if(lastPreferCount < M){ // 총합 선호도가 아예 도달하지 못하면 -1을 출력
		return -1;
	}
	return degreeLevel;
}
bool sortByDegree(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// N = 축제가 열리는 기간, M = 채워야 하는 선호도의 합, K = 맥주 종류의 수
	cin >> N >> M >> K; 
	vector<pair<int, int> > beer_info;

	// 첫번째 요소는 맥주의 선호도, 두번째 요소는 도수 레벨
	// 맥주의 정보를 입력받는다.
	for(int i=0; i<K; i++){
		pair<int, int> beer;
		cin >> beer.first >> beer.second;
		beer_info.push_back(beer);
	}
	sort(beer_info.begin(), beer_info.end(), sortByDegree);
	#if DEBUG_MODE
	for(int i=0; i<K; i++){
		cout << "선호도 = " << beer_info[i].first << "  도수 레벨 = " << beer_info[i].second << '\n';
	}
	#endif
	cout << solution(beer_info) << '\n';
	return 0;
}
