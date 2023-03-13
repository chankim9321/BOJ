#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
void sol(vector<char> v, int result, int depth);
void init(){
	int tc;
	cin >> tc;
	for(int i=0; i<tc; i++){
		cin >> n;
		vector<char> v;
		v.push_back('1');
		sol(v, 1, 1);
		cout << '\n';
	}
}
void sol( vector<char> v, int result, int depth){
	if(depth == n){
		if(result == 0){
			for(auto c : v){
				cout << c;
			}
			cout << '\n';
		}
		return;
	}
	vector<char>vSpace = v;	
	vSpace.push_back(' ');
	vSpace.push_back(depth+1 + '0');
	int tmp = result;
	if(v.size() > 2){
		int preOperIdx = v.size() - 2;
		if(v[preOperIdx] == '+'){
			tmp = result - depth + (10*depth + (depth+1));
			sol(vSpace, tmp, depth +1);
		}
		else if(v[preOperIdx] == '-'){
			tmp = result + depth - (10*depth + (depth+1));	
			sol(vSpace, tmp, depth +1);
		}
	}
	else sol(vSpace, 12, depth+1);

	vector<char> vPlus = v;
	vPlus.push_back('+');
	vPlus.push_back(depth+1 + '0');
	sol(vPlus, result + (depth+1), depth+1);

	vector<char> vMinus = v;
	vMinus.push_back('-');
	vMinus.push_back(depth+1 + '0');
	sol(vMinus, result - (depth+1), depth+1);
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	return 0;
}
