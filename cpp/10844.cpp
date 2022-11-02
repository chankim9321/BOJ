#include <iostream>
#define MOD 1000000000
using namespace std;


int memory[101][10] = {0,};

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int size;
	cin >> size;

	for(int i=0; i<10; i++){
		memory[1][i] = 1;
	}
	for(int i=2; i<=size; i++){
		for(int j=0; j<10; j++){
			if(j == 0 || j == 9){
				if(j == 0) memory[i][j] = (memory[i-1][j+1] % MOD);
				else memory[i][j] = (memory[i-1][j-1] % MOD);
			}
			else {
				memory[i][j] = (memory[i-1][j-1] + memory[i-1][j+1]) % MOD;
			}
		}
	}
	long long result = 0;

	for(int i=1; i<10; i++){
		result = (result + memory[size][i] % MOD;
	}
	cout << result << '\n';

	return 0;
}
