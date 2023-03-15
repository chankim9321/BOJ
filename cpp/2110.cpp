#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG_MODE 0
using namespace std;

int solution(int router, vector<int>& v){
	int ans=0;
	int mid;

	int start = v.front(); // minimum
	int end = v.back(); 
	
	int installed;
	int st;
	// 1 2 4 8 9
	while(start <= end){
		installed = 1;
		mid = (start + end)/2;
		st = v[0];
		for(int i=1; i<v.size(); i++){
			if(v[i] - st>= mid){
				st = v[i];
				installed++; 
			}
		}
		if(installed >= router){ 
			ans = max(ans, mid);	
			start = mid+1;
		}
		else{
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
