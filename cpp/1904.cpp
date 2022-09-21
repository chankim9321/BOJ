#include <iostream>
#include <string>
using namespace std;
#define MAX 1000000 
int cache[MAX] = {0,};

/*
int facto(int n){
	int res=1;
	for(int i=n; i>0; i--){
		res = res*i;
	}
	return res;
}
int comb(int n, int r){
	if(r == 0) return 1;
	if(r == 1) return n;
	return facto(n) / (facto(n-r)*facto(r));
}
*/

// A recurrence fomula is "D[n] = D[n-1] + D[n-2]"
int solution(int n){
	if(n==1) return 1; // D[1] = 1
	if(n==2) return 2; // D[2] = 2

	if(cache[n] == 0){
		return cache[n] = solution(n-1) + solution(n-2);
	}
	else{
		return cache[n];
	}
}
int main(int argc, char* argv[]){
	int size;
	cin >> size;
	cout << solution(size) << "\n";
	return 0;
}
