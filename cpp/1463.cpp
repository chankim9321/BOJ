#include <iostream>
#define AND &&
#define OR ||
using namespace std;
int getMin(int a, int b){
	return a < b ? a : b;
}
int solution(int number){
	int *DP = new int[number+1];
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;
	for(int i=4; i<=number; i++){
		DP[i] = DP[i-1] + 1;
		if(i%2 == 0){
			DP[i] = getMin(DP[i], DP[i/2] + 1);
		}
		if(i%3 == 0){
			DP[i] = getMin(DP[i], DP[i/3] + 1);
		}
	}
	return DP[number];
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int number;
	cin >> number;
	cout << solution(number) << "\n";
	return 0;
}
