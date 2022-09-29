#include <iostream>
#include <vector>

using namespace std;
long solution(long arr[], int needs, int wrans, long max){
	long start = 0;
	long end = max;
	int result;
	long mid;
	int slices;
	long answer;
	while(start <= end){
		result = 0;
		mid = (start + end)/2;
		if(mid == 0){
			mid++;
		}
		for(int i=0; i<wrans; i++){
			slices = arr[i] / mid;
			result += slices;	
		}
		if(result >= needs) { // 조건을 만족하고도 남는다면
			start = mid+1;
			answer = mid;
		}
		else end = mid-1;
	}
	return answer;
}
int main(int argc, char* argv[]){
	int wrans;
	int needs;

	cin >> wrans >> needs;
	long *arr = new long[wrans];
	long max = 0;
	for(int i=0; i<wrans; i++){
		cin >> arr[i];
		if(arr[i] > max){
			max = arr[i];	
		}
	}
	cout << solution(arr, needs, wrans, max) << '\n';
	return 0;
}
