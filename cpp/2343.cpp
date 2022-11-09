#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int numOfLect, numOfBr;
	cin >> numOfLect >> numOfBr;

	int lect[numOfLect];
	long long maxLength=0;
	int minLength=10e8;
	for(int i=0; i<numOfLect; i++){
		cin >> lect[i];
		minLength = min(minLength, lect[i]);
		maxLength += lect[i];
	}
	while(minLength <= maxLength){
		long long mid = (minLength + maxLength)/2; // 선정된 블루레이의 길이
		int count=0;
		long long sum=0;
		for(int i=0; i<numOfLect; i++){
			if(sum + lect[i] > mid){
				count++;
				sum = 0;
			}
			sum += lect[i];
		}
		if(sum != 0) count++;
		if(count > numOfBr){
			minLength = mid+1;
		}
		else {
			maxLength = mid-1;
		}
	}
	cout << minLength << '\n';
	return 0;
}
