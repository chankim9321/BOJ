#include <iostream>
#include <vector>

using namespace std;
int solution(int arr[], int needs, int wrans, int max){
	int start = 0;
	int end = max;
	int result;
	int mid;
	int slices;
	int answer;
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
	int *arr = new int[wrans];
	int max = 0;
	for(int i=0; i<wrans; i++){
		cin >> arr[i];
		if(arr[i] > max){
			max = arr[i];	
		}
	}
	cout << solution(arr, needs, wrans, max) << '\n';
	return 0;
}
