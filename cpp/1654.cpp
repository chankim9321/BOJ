#include <iostream>
#include <vector>

using namespace std;
int solution(int arr[], int needs, int wrans, int max){
	int start = 0;
	int end = max;
	int result;
	int mid;
	int slices;
	while(!(result == needs)){
		result = 0;
		mid = (start + end)/2;
		for(int i=0; i<wrans; i++){
			slices = arr[i] / mid;
			result += slices;	
		}
		if(result > needs) start = mid;
		else if(result < needs) end = mid;
	}
	return mid;
}
int main(int argc, char* argv[]){
	int wrans;
	int needs;

	cin >> wrans >> needs;
	int *arr = new int[wrans];
	int max=0;
	for(int i=0; i<wrans; i++){
		cin >> arr[i];
		if(arr[i] > max){
			max = arr[i];	
		}
	}
	cout << solution(arr, needs, wrans, max) << '\n';
	return 0;
}
