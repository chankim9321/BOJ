#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);

	int numberSize;
	cin >> numberSize;
	int number[numberSize];
	for(int i=0; i<numberSize; i++){
		cin >> number[i];
	}
	vector<int> seqComb;
	for(int i=0; i<4; i++){
		// 0 = + ,1 = - ,2 = * ,3 = /
		int operate;
		cin >> operate;
		for(int j=0; j<operate; j++){
			seqComb.push_back(i);
		}
	}
	int maxResult = -1000000000;
	int minResult = 1000000000;
	do{
		int res = number[0];
		for(int i=0; i<numberSize-1; i++){
			if(seqComb[i] == 0) res+=number[i+1];	
			else if(seqComb[i] == 1) res-=number[i+1];
			else if(seqComb[i] == 2) res*=number[i+1];
			else res/=number[i+1];
		}
		maxResult = max(maxResult, res);
		minResult = min(minResult, res);
		
	}while(next_permutation(seqComb.begin(), seqComb.end()));
	
	cout << maxResult << '\n' << minResult << '\n';
	return 0;
}
