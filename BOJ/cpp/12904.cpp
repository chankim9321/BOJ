#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string s, t;
bool flag = false;
void init(){
	cin >> s >> t;
}
void backTracking(string input){
	if(flag) return;
	if(input.length() == t.length()){
		if(input == t) flag = true;
		return;
	}
	string next1 = input;
	string next2 = input;
	next1 += "A";
	reverse(next2.begin(), next2.end());
	next2 += "B";
	backTracking(next1);
	backTracking(next2);
}
void sol(){
	init();
	backTracking(s);
	if(flag) cout << 1 << '\n';
	else cout << 0 << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sol();

	return 0;
}
