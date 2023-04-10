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
void sol(){
	init();

	while(1){
		if(t[t.length()-1] == 'A'){
			t.pop_back();
		}
		else{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		if(t.length() == s.length()){
			if(s == t) flag = true;
			break;
		}
	}

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
