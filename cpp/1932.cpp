#include <iostream>
#define AND &&
#define OR ||
using namespace std;
int getMax(int a, int b){
	return a > b ? a : b;
}
int getSumOfSeq(int n){
	return ((n*(n+1)/2));
}
int solution(int arr[], int arrSize){
	int preStartIdx = 0;
	int preEndIdx = 0;
	// 1층 기준 변수들의 정보
	int elements = 2;
	int startIdx = 1;
	// update 과정 
	for(int i=1; i<arrSize; i++){
		// 부모 노드가 1개인 경우
		if(i == startIdx){ // 층의 첫 인덱스
			arr[i] += arr[preStartIdx];
			startIdx += elements; // 다음 층의 첫 인덱스는 현재 인덱스 + 현재 층 원소 갯수
			preStartIdx = i;
		}
		else if(i == (startIdx - 1)){ // 층의 끝 인덱스
			arr[i] += arr[preEndIdx];
			elements++; // 다음 인덱스는 층이 증가하므로 원소갯수 1증가
			preEndIdx = i; // 현재 층 기록
		}
		// 부모 노드가 2개인 경우
		else{ 
			int a = arr[i - elements] + arr[i]; // 왼쪽 부모노드
			int b = arr[i - elements + 1 ] + arr[i]; // 오른쪽 부모노드
			arr[i] = getMax(a,b); // update
		}
	}
	// 마지막 층에서 최댓값 찾기
	int max = arr[preStartIdx];
	for(int i = preStartIdx; i<arrSize; i++){ // 마지막 층에서 max값을 찾는다
		if(arr[i] > max) max = arr[i];	
	}
	return max;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int size;
	cin >> size;
	int arrSize = getSumOfSeq(size);
	int *arr = new int[arrSize];
	
	int idx=0;
	for(int i=0; i<arrSize; i++){
		cin >> arr[i];
	}

	cout << solution(arr, arrSize) << "\n";
	delete[] arr;
	return 0;
}
