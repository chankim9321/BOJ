#include <iostream>
#define OR ||
#define AND &&
using namespace std;
int recursive=0;
int dynamic=0;
int f[41]={0,};
int fib(int n){
	if(n == 1 OR n == 2) {
		recursive++;
		return 1;
	}
	return fib(n-1) + fib(n-2);
}
int fibonacci(int n){
	dynamic = n - 2;
	f[1] = 1;
	f[2] = 1;
	for(int i=3; i<=n; i++){
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}
int main(int argc, char* argv[]){
	int repeat;
	cin >> repeat;
	int result_1 = fib(repeat); 
	int result_2 = fibonacci(repeat);
	cout << recursive << " " << dynamic << "\n";
	return 0;
}
