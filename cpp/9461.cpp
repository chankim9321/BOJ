#include <iostream>
#define OR ||
#define AND &&
using namespace std;

long long cache[101]= {0,};

long long solution(int n){
	if(n==1 OR n==2 OR n==3) return 1;
	if(cache[n] == 0){
		return cache[n] = solution(n-2) + solution(n-3);
	}
	else return cache[n];
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int testcase;
	cin >> testcase;
	for(int i=0; i<testcase; i++){
		int size;
		cin >> size;
		cout << solution(size) << "\n";
	}
	return 0;
}
