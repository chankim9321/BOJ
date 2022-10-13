#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define DEBUG_MODE 1
using namespace std;

int N, K;
long long M;
int solution(vector<pair<long long, long long> >&v){
	int start = 0; // 시작인덱스
	int end = v.size()-1; // 끝 인덱스 
	long long lastPreferCount;
	long long preferCount=0;
	long long degreeLevel=5000000000;
	// 현재 벡터는 도수레벨을 기준으로 오름차순 정렬되어 있음.
	while(start <= end){
		int mid = (start + end)/2; // 중간 인덱스 ex) 2
	//	cout << "산정된 인덱스값 = " << mid <<  ", 해당 인덱스값에 존재하는 도수레벨 = " << v[mid].second << '\n';
		if(mid < N-1){ // 선정된 인덱스값이 마셔야 되는 술보다 작을경우
		//	cout << N << "잔을 마실 수 없으므로 도수레벨을 좀 더 높입니다." << '\n';
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
