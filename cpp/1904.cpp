#include <iostream>
#include <string>
using namespace std;

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
int solution(int n){
	if(n == 1) return 1;
	int res=0;	
	int r = n/2;
	if(n % 2 == 0){
		n/=2;
	}
	else{
		n = n/2 + 1;
	}
	for(int i=r; i>=1; i--){
		res += comb(n,i);
		n++;
	}
	return res + 1; 
}
int main(int argc, char* argv[]){
	int size;
	cin >> size;
	cout << solution(size) << "\n";
	return 0;
}
