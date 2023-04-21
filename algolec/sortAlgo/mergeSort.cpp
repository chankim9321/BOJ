#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int number = 8;
int sorted[8];

void merge(int a[], int m, int middle, int n){
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
void mergeSort(int a[], int m, int n){
	if(m < n){
		int middle = (m+n)/2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		merge(a, m, middle, n);
	}
}
int main(int argc, char *argv[]){
	fastio;
	int arr[] = {37,10,22,30,35,13,25,24};
	cout << "정렬 전" << '\n';
	for(int i=0; i<8; i++) cout << arr[i] << " ";
	cout << '\n';
	mergeSort(arr, 0, 7);
	cout << "정렬 후" << '\n';
	for(int i=0; i<8; i++) cout << arr[i] << " ";
	cout << '\n';
	
	return 0;
}
