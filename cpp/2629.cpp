#include <iostream>
using namespace std;

int solution(int items[], int beadWeight, int weightSum, int seq){
	if(beadWeight == weightSum) return 1;	
	if(seq == -1) return 0;
	else{
		int plusBeadWeight = beadWeight + items[seq]; // 구슬쪽에 무게추를 추가하는 경우
		int minusBeadWeight = beadWeight - items[seq]; // 무게추를 추가하지 않는 경우( 무게추 쟁반에 올려놓는 경우)
		weightSum -= items[seq];
		seq--;
		// 무게추를 사용해서 구슬 쟁반에 놓는 경우, 무게추쟁반에 놓는 경우, 해당 무게추를 사용하지 않는 경우
		return max(solution(items, plusBeadWeight, weightSum, seq), max(solution(items, minusBeadWeight, weightSum, seq), solution(items,beadWeight,weightSum,seq)));
	}
}
int main(int argc, char* argv[]){
	// fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int weight;
	cin >> weight;
	int items[weight];
	int weightSum = 0; // 무게추의 합
	for(int i=0; i<weight; i++){
		cin >> items[i];
		weightSum += items[i];
	}
	int beads;
	cin >> beads;
	for(int i=0; i<beads; i++){
		int beadWeight;
		cin >> beadWeight;
		if(solution(items, beadWeight, weightSum, weight-1) == 1){
			cout << "Y ";
		}
		else{
			cout << "N ";
		}
	}
	return 0;
}
