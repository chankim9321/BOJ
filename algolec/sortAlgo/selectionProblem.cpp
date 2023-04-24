#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> li = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14};
int partition(int left, int right){
	int pivot = (left + right)/2;
	swap(li[pivot], li[left]);	
	int i = left + 1;
	int j = right;
	while(i <= j){
		while(li[i] <= li[left] && i <= right) i++;
		while(li[j] >= li[left] && j > left) j--;
		if(i > j){
			swap(li[left], li[j]);
		}
		else{
			swap(li[i], li[j]);
		}
	}
	return j; // 피벗 인덱스 반환
}
int selection(int k,  int left, int right){
	if(left >= right) return li[left]; // 원소가 1개라면

	int pivotIdx = partition(left, right);
	int groupSize = pivotIdx - left;

	if(k < groupSize) return selection(k, left, pivotIdx-1); // k가 그룹사이즈보다 작다면 왼쪽 그룹에서 찾아야함
	else if(k > groupSize) return selection(k-pivotIdx-1, pivotIdx+ 1, right); // 
	else return li[pivotIdx];
}
int main(int argc, char* argv[]){
	int k = 7;
	cout << selection(k, 0, li.size() -1) << '\n';
	sort(li.begin(), li.end());
	for(const auto v : li){
		cout << v << " ";
	}
	cout << '\n';
}
