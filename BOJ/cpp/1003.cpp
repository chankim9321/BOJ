#include <iostream>
#include <vector>
using namespace std;

int hist[41] = {0,};
pair<int, int> arr[41];

int fibo(int n){
	if(hist[n] != 0) return hist[n];
	else if(n == 0){
		arr[n].first = 1;
		return 0;
	}
	else if(n == 1){
		arr[n].second = 1;
		return 1;
	}
	else{
		hist[n] = fibo(n-1) + fibo(n-2);	
		arr[n].first = arr[n-1].first + arr[n-2].first;
		arr[n].second = arr[n-1].second + arr[n-2].second;
		return hist[n];
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCase;
	cin >> testCase;	
	
	for(int i=0; i<testCase; i++){
		int number;
		cin >> number;
		int result = fibo(number);
		cout << arr[number].first << " " << arr[number].second << '\n';
	}
	return 0;
}
