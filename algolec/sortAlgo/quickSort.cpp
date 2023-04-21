#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int a[], int left, int right){
	/*
	for(int i=left; i <= right; i++){	
		cout << a[i] << " ";
	}
	*/
	cout << '\n';
	if(left < right){
		int pivot = (left + right)/2; // set pivot
	//	cout << "피벗 인덱스 = " << pivot << ", left = " << left << ", right = " << right <<  '\n';
	//	cout << "피벗 = " << a[pivot] << '\n';
		swap(a[pivot], a[left]);	 // 피벗과 맨 왼쪽 원소와 자리교체
		int i = left+1;
		int j = right;
		while(i <= j){
			while(a[i] >= a[left] && i <= right){ // 왼쪽에서 시작한 값이 현재 피벗값보다 클 때 까지 탐색
				i++;	
			}
			while(a[j] <= a[left] && j > left){ // 오른쪽에서 시작한 값이 현재 피벗 값보다 작을 때 까지
				j--;
			}
			// 두 반복문을 탈출 했을때는 i와 j를 교체해야함
			// 하지만 이미 엇갈렸다면 피벗과 마지막으로 교체된 값과 자리 바꾸기
			if( i > j){
				swap(a[left], a[j]);
			}
			else swap(a[i], a[j]);
		}
		quickSort(a, left, j-1);
		quickSort(a, j+1, right);
	}
}
int main(){
	int arr[] = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14};
	for(const auto i : arr){	
		cout << i << " ";
	}
	cout << '\n';
	quickSort(arr, 0, 11);
	for(const auto i : arr){	
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}
