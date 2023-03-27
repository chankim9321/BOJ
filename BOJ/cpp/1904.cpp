#include <iostream>
#include <string>
using namespace std;
#define MAX 1000001 
#define REMAINDER 15746
int cache[MAX] = {0,};

// A recurrence fomula is "D[n] = D[n-1] + D[n-2]"
long long solution(int n){
	if(n==1) return 1; // D[1] = 1
	if(n==2) return 2; // D[2] = 2

	if(cache[n] == 0){
		return cache[n] = (solution(n-1) + solution(n-2)) % REMAINDER;
	}
	else{
		return cache[n];
	}
}
long long solution_2(int n){
	cache[1]=1;
	cache[2]=2;
	for(int i=3; i<=n; i++){
		cache[i] = (cache[i-1] + cache[i-2]) % REMAINDER;
	}
	return cache[n];
}
int main(int argc, char* argv[]){
	//set fast IO
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);

	int size;
	cin >> size;
	cout << solution_2(size) << "\n";
	return 0;
}
