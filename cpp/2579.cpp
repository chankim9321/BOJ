#include <iostream>
#include <algorithm>
using namespace std;
int solution(int stairs, int arr[]){
	int DP[stairs+1];
	fill(DP,DP+stairs+1,0);
	DP[1] = arr[1];
	DP[2] = DP[1] + arr[2];
	for(int i=3; i<=stairs; i++){
		// 전자는 0 -> 2 -> 3
		// 후자는 0 -> 1 -> 3
		// 전자의 경우가 조금 복잡한데, 2번째 칸은 0 -> 2, 0 -> 1 -> 2 로 나뉜다.
		// 전자가 더 크려면 0 -> 1 -> 2 순서가 이루어지면 3번째 계단은 밟지 못하므로 0 -> 2 순으로 이어져야 한다.
		DP[i] = max(DP[i-3] + arr[i-1] + arr[i], DP[i-2] + arr[i]);
	}
	return DP[stairs];
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int stairs;
	cin >> stairs;
	int *arr = new int[stairs+1];
	for(int i=1; i<=stairs; i++){
		cin >> arr[i];	
	}
	cout << solution(stairs, arr) << '\n';
	return 0;
}
