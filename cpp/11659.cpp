#include <iostream>
#include <vector>
using namespace std;
int numbers, sums;

void sol(int arr[], pair<int, int> range){
	int sum = 0;
	for(int i=1; i<=numbers; i++){
		if(i >= range.first && i <= range.second){
			sum += arr[i];
		}
	}
	cout << sum << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> numbers >> sums;
	int arr[numbers+1];
	for(int i=1; i<=numbers; i++){
		cin >> arr[i];
	}
	for(int i=0; i<sums; i++){
		pair<int, int> range;
		cin >> range.first >> range.second;
		sol(arr, range);
	}
	return 0;
}
