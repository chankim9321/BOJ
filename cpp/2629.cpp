#include <iostream>
#include <cstdlib>
using namespace std;

int items[30];
int dp[31][15001]; // 추의 갯수와 모든 추를 이용한 나올수 있는 조합의 최대
int weight;
// beadWeight 를 0으로 만드는게 목적.
// 즉, 추의 갯수를 변화시키면서 beadWeight 가 0인 값이 true가 되면 목적 달성.
void sol(int seq, int beadWeight){
	if(seq>weight || dp[seq][weight] == 1) return;	
	dp[seq][beadWeight] = 1;
	sol(seq+1, beadWeight + items[seq]); // 구슬 쟁반에 추를 추가하는 경우
	sol(seq+1, abs(beadWeight - items[seq])); // 추 쟁반에 추를 추가하는 경우 --> 구슬 쟁반의 무게가 줄어든걸로 간주
	sol(seq+1, beadWeight); // n번째에 있는 추를 버리는 경우
}
int main(int argc, char* argv[]){
	// fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> weight;
	int weightSum = 0; // 무게추의 합
	for(int i=0; i<weight; i++){
		cin >> items[i];
		weightSum += items[i];
	}
	sol(0,0);
	int beads;
	cin >> beads;
	for(int i=0; i<beads; i++){
		int beadWeight;
		cin >> beadWeight;
		if(dp[weight][beadWeight] == 1){
			cout << "Y ";
		}
		else{
			cout << "N ";
		}
	}
	return 0;
}
