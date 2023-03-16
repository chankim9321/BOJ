#include <iostream>
#include <algorithm>
#define MOD 10007
using namespace std;

int main(int argc, char* argv[]){
	int size;
	cin >> size;
	int memory[1001][10] = {0,};
	for(int i=0; i<10; i++){
		memory[1][i] = 1;
	}
	for(int i=2; i<=size; i++){
		memory[i][0] = 1;
		for(int j=1; j<10; j++){
			memory[i][j] = memory[i][j-1] + memory[i-1][j];
			memory[i][j] %= MOD;
		}
	}
	int res=0;
	for(int i=0; i<10; i++){
		res += memory[size][i];
	}
	cout <<  res % MOD << '\n';
	return 0;
}

