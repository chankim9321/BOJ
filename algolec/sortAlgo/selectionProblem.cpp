#include <iostream>
#include <vector>
using namespace std;
vector<int> li = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14};
int partition(int left, int right){
	int pivot = li[right];
	int pivot_idx = right;

	right--;
	while(1){
		while(li[left] < pivot) left++;
		while(li[right] > pivot) right--;
		if(left >= right) break;
		else{
			swap(li[left], li[right]);
			left++;
		}
	}
	swap(li[left], li[pivot_idx]);
	return left;
}
int selection(int k,  int left, int right){
	if(left >= right) return li[left];
	int pivot_idx = partition(left, right);

	if(k < pivot_idx) return selection(k, left, pivot_idx-1);
	else if(k > pivot_idx) return selection(k, pivot_idx + 1, right);
	else return li[pivot_idx];
}
int main(int argc, char* argv[]){
	int k = 7;
	cout << selection(k-1, 0, li.size() -1) << '\n';
}
