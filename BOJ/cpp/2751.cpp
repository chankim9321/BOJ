#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void merge(int a[], int sorted[], int m, int middle, int n){
	int i = m; // 첫번째 배열의 시작점
	int j = middle + 1; // 두번째 배열의 시작점
	int k = m; // 정렬될 배열의 시작점
	
	while(i <= middle && j <= n){
		if(a[i] <= a[j]){
			sorted[k++] = a[i++];
		}
		else if(a[i] > a[j]){
			sorted[k++] = a[j++];
		}
	}
	// 나머지 배열은 이미 정렬되어있으므로 마저 넣어준다
	if(i > middle){
		for(int t=j; t<=n; t++) sorted[k++] = a[t];
	}
	else{
		for(int t=i; t <= middle; t++) sorted[k++] = a[t];
	}
	// 실제 배열로 업데이트
	for(int t=m; t<=n; t++) a[t] = sorted[t];
}
void mergeSort(int a[], int sorted[], int m, int n){
	if(m < n){
		int middle = (m+n)/2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted,  middle+1, n);
		merge(a, sorted, m, middle, n);
	}
}
int main(int argc, char *argv[]){
	fastio;
	int n;
	cin >> n;
	int* arr = new int[n];
	int* sorted = new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];	
	}

	mergeSort(arr, sorted, 0, n-1);
	for(int i=0; i<n; i++) cout << arr[i] << "\n";
	
	delete[] arr;
	delete[] sorted;

	return 0;
}
	
