#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	string s;
	cin >> s;
	int zero = 0, one = 0;
	for(int i=0; i<s.length(); i++){
		if(s[i] == '0') zero++;
		else one++;
	}
	string ss = "";
	for(int i=0; i<zero/2; i++){
		ss += "0";
	}
	for(int i=0; i<one/2; i++){
		ss += "1";
	}
	cout << ss << '\n';
	return 0;
}
