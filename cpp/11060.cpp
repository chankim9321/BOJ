#include <iostream>
#include <algorithm>
#define INF 9999999

using namespace std;
int solution(int size, int arr[]){
	if(arr[1] == 0 && size != 1) return -1; // 첫 요소부터 0이면 점프가 불가능 하므로 -1반환
	int DP[size+1];
	fill(DP, DP+size+1, INF);
	DP[1] = 0;
	for(int i=2; i<=size; i++){
		for(int k=0; k<arr[i-1]; k++){
			if(i+k > size) break;
			DP[i+k] = min(DP[i-1] + 1, DP[i+k]);		
		}
	}
	return DP[size] != INF ? DP[size] : -1; // 업데이트가 됬다면 
}
int main(int argc, char* argv[]){
	int size;
	cin >> size;
	int *arr = new int[size+1];
	for(int i=1; i<=size; i++){
		cin >> arr[i];	
	}
	cout << solution(size, arr) << '\n';
	return 0;
}
