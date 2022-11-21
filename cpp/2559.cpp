#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int length, range;
	cin >> length >> range;
	int arr[length+1];
	arr[0] = 0;

	int result=-1;
	for(int i=1; i<=length; i++){
		int num;
		cin >> num;
		arr[i] = num + arr[i-1];
		if(i >= range){
			result = max(result, arr[i] - arr[i-range]);
		}
	}
	cout << result << '\n';
	return 0;
}
