#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 4000001
using namespace std;

int n;
vector<bool> v;
vector<int> prime;
void init(){
	cin >> n;
	v.resize(MAX_SIZE, true);
}
void setPrimeNumbers() {
	v[1] = false;
	for(int i=2; i<MAX_SIZE; i++){
		if(!v[i]) continue;
		prime.push_back(i);
		for(int j=i; j<MAX_SIZE; j = j + i){
			if(v[j]) v[j] = false;
		}
	}
}
void sol(){
	int result = 0;
	int left = 0, right = 0;
	int sum = 0;
	while(left <= right && right <= prime.size()){
		if(sum >= n){
			if(sum == n) result++;
			sum -= prime[left++];
		}
		else{
			if(right == prime.size()) break;
			sum += prime[right++];
		}
	}
	cout << result << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	setPrimeNumbers();
	sol();
	return 0;
}
