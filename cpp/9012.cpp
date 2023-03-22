#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	for(int i=0; i<tc; i++){
		string input;
		cin >> input;
		stack<char> s;
		bool wrong = false;
		for(int k=0; k<input.length(); k++){
			// 문자열을하나씩 검사
			if(input[k] == '('){
				s.push(')');
			}
			else{
				if(!s.empty()){
					s.pop();
				}
				else wrong = true;
			}
		}
		if(!s.empty() || wrong) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}

