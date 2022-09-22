#include <iostream>
#define MAX 100000
#define AND &&
#define OR  ||
using namespace std;
int arr[MAX+1]; // original
int solution(int n){
	int max=-1001;
	for(int i=1; i<=n; i++){
		if(arr[i-1] > 0 AND arr[i] + arr[i-1] > 0){
			arr[i]+=arr[i-1];
		}
		if(arr[i] > max) max = arr[i];
	}
	return max;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int seqSize;
	cin >> seqSize;
	for(int i=0; i<seqSize; i++){
		cin >> arr[i];
	}
	cout << solution(seqSize) << "\n";
	return 0;
}
