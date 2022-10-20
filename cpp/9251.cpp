#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

vector<vector<int> > memory(MAX, vector<int>(MAX, -1));

int LCS(string x, string y){
	int a = x.size();
	int b = y.size();

	if(a == 0 || b == 0) return 0;
	else{
		if(x.back() == y.back()){
			if(memory[a][b] != -1) return memory[a][b];
			else return memory[a][b] = LCS(x.substr(0,a-1),y.substr(0,b-1)) + 1;
		}
		else{
			return memory[a][b] = max(LCS(x,y.substr(0,y.size()-1)), LCS(x.substr(0,x.size()-1),y));
		}
	}
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
