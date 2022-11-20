#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int numbers, sums;
	cin >> numbers >> sums;
	int arr[numbers+1];
	arr[0] = 0;
	for(int i=1; i<=numbers; i++){
		cin >> arr[i];
	}
	for(int i=2; i<=numbers; i++){ // init prefix sum
		arr[i] += arr[i-1];
	}
	for(int i=0; i<sums; i++){
		pair<int, int> range;
		cin >> range.first >> range.second;
		cout << arr[range.second] - arr[range.first-1] << '\n';
	}
	return 0;
}
