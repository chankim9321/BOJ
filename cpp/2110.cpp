#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int solution(int routers, vector<int>& v){
	ll ans=0;
	ll mid;

	ll start = 0; // minimum
	ll end = v.back(); 
	
	int installed;
	int router;
	// 1 2 4 8 9
	while(start <= end){
		installed = 1;
		mid = (start + end)/2; // 설정한 임의의 거리값
		router = v[0];
		for(int i=1; i<v.size(); i++){
			if(v[i] - router >= mid){ // 공유기를 설치한 장소가 설정한 임의의 거리값보다 큰 경우 --> 공유기 설치
				router = v[i];
				//cout << "임의의 거리값 : " << mid << ", 설치된 장소의 좌표: " << st << '\n';
				installed++; 
			}
			if(installed > routers) break;
		}
		//cout << "설치된 공유기의 수 : " << installed << '\n';
		if(installed >= routers){ // 거리간격을 늘려서 공유기의 설치수를 줄여야함.
			ans = max(ans, mid);	
			start = mid+1;
		}
		else{ // 공유기 설치가 요구수보다 작기때문에 거리간격을 늘려야한다.
			end = mid-1;
		}
	}
	return ans;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int node;
	int router;
	cin >> node >> router;
	vector<int> v; // 동적으로 생성한 노드를 저장하는 벡터

	for(int i=0; i<node; i++){ // init
		int dist;
		cin >> dist;
		v.push_back(dist);
	}
	sort(v.begin(), v.end()); // 오름차순으로 정렬
	cout << solution(router, v) << '\n';
	return 0;
}
