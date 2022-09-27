#include <iostream>
using namespace std;
int getMax(int a, int b){
	return a > b ? a : b;
}
int solution(int stairs, int arr[]){
	int DP[stairs+1];
	DP[1] = arr[1]; // 10
	DP[2] = arr[2] + DP[1]; // 30
	DP[3] = arr[3] + DP[1];  // 25
	for(int i=4; i<=stairs; i++){
		DP[i] = arr[i] + DP[i-1]; // 계단에서 1칸 올라왔을 때
		if(DP[i-1] == DP[i-2] + arr[i-1]){ // 이전 연산에서 이미 1칸을 올라왔다면 연속해서 3칸을 이미 올라갈 수 없다.
			DP[i] = arr[i] + DP[i-2]; // 따라서 두칸을 바로 올라가는 수 밖에 없다.
		}
		else{
			DP[i] = getMax(arr[i] + DP[i-2], DP[i]); // 2칸 올라왔을 때 와 1칸 올라왔을 때 누적 비용을 비교
		}
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
