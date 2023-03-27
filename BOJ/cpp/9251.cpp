#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

vector<vector<int> > memory(MAX, vector<int>(MAX, 0));

int LCS(string x, string y){
	int a = x.size();
	int b = y.size();

	for(int i=1; i<=a; i++){
		for(int j=1; j<=b; j++){
			if(x[i-1] == y[j-1]){
				memory[i][j] = memory[i-1][j-1]+1;
			}
			else{
				memory[i][j] = max(memory[i-1][j], memory[i][j-1]);
			}
		}
	}
	return memory[a][b];
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a,b;
	getline(cin,a);
	getline(cin,b);
	cout << LCS(a,b) << '\n';
	return 0;
}
