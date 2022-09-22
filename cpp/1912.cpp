#include <iostream>
#include <vector>
#define MAX 100000
#define AND &&
#define OR  ||
using namespace std;
int arr[MAX];
int size;
int cache[MAX+1];
int getMaxSeqNumber(int seqLength){ // 수열의 길이를 인자로 받는다.
	int max = -1001; // 수열의 가장 최솟값
	for(int i=0; i<size; i++){
		int res=0;
		for(int j=0; j<seqLength; j++){
			res = res + arr[i+j];
			if(res > max) max = res;
		}
	}
	return max;
}
int solution(){
	// cache 배열은 수열의 연속된 길이의 따른 최댓값을 저장한 배열
	for(int i=1; i<=size; i++){
		cache[i] = getMaxSeqNumber(i);
	}
	int max=-1001;
	for(int i=1; i<=size; i++){
		if(max < cache[i]) max = cache[i];	
	}
	return max;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> size;
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
	cout << solution() << "\n";
	return 0;
}
