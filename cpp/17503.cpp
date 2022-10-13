#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define DEBUG_MODE 0
using namespace std;

int N, K;
long long M;
int solution(vector<pair<long long, long long> >&v){
	int start = 0; // 시작인덱스
	int end = v.size()-1; // 끝 인덱스 
	long long preferCount=0;
	long long degreeLevel=1e13;
	// 현재 벡터는 도수레벨을 기준으로 오름차순 정렬되어 있음.
	while(start <= end){
		int mid = (start + end)/2; // 중간 인덱스
		if(mid < N-1){ // 선정된 인덱스값이 마셔야 되는 술보다 작을경우
			start= mid+1;		
			continue;
		}
		priority_queue<pair<long long, long long> > max_heap;
		for(int i=0; i<=mid; i++){ 
			max_heap.push(v[i]); // 선정된 인덱스 아래로 모든 데이터를 삽입
		}
		for(int i=0; i<N; i++){ // N개 만큼 선호도가 높은 순서대로 꺼낸다.
			preferCount += max_heap.top().first;
			max_heap.pop();
		}
		//cout << "산정된 선호도의 합 = " << preferCount << ", 도수레벨 : " << v[mid].second << '\n';
		if(preferCount < M){ // 선호도의 합이 요구하는 총합 선호도보다 낮을 떄는 레벨을 올릴 필요가 있다.
			start = mid+1;
		}
		else { // 선호도의 합이 요구하는 총합 선호도보다 높을 때는 레벨을 줄일 필요가 있다.
			end = mid-1;
			degreeLevel = min(degreeLevel, v[mid].second); // 현재 도수레벨 기록
		}
		preferCount = 0; // 재 초기화
	}
	return (degreeLevel != 1e13 ? degreeLevel : -1);
}
bool sortByDegree(pair<long, long> a, pair<long, long> b){
	return a.second < b.second;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// N = 축제가 열리는 기간, M = 채워야 하는 선호도의 합, K = 맥주 종류의 수
	cin >> N >> M >> K; 
	vector<pair<long long, long long> > beer_info;

	// 첫번째 요소는 맥주의 선호도, 두번째 요소는 도수 레벨
	// 맥주의 정보를 입력받는다.
	for(int i=0; i<K; i++){
		pair<long long, long long> beer;
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
