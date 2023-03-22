#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, bool> dict;
void init(){
	dict["c="] = true;
	dict["c-"] = true;
	dict["dz="] = true;
	dict["d-"] = true;
	dict["lj"] = true;
	dict["nj"] = true;
	dict["s="] = true;
	dict["z="] = true;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	string input;
	cin >> input;
	int croAlpha = 0;
	int idx = 0;
	string s = "";
	while(idx < input.length()){
		string c(1, input[idx++]);
		s = s + c;
		if(dict.find(s) != dict.end()){
			croAlpha++;	
			s = "";	
		}
		else if(s.length() == 4){ 
			if(dict.find(s.substr(1,2)) != dict.end()){
				croAlpha += 2; // 맨앞 문자와 중간 2글자 알파벳
				s = s.substr(3);
			}
			else if(dict.find(s.substr(1)) != dict.end()){
				croAlpha += 2; // 맨앞 문자와 뒤에 3글자 알파벳
				s = "";
			}
			else if(dict.find(s.substr(2)) != dict.end()){
				croAlpha += 3; // 앞에 2개의 알파벳과 2글자 알파벳
				s = "";	
			}
			else{
				s = s.substr(1); // 맨 뒤 문자 제거
				croAlpha++;
			}
		}
	}
	cout << croAlpha + s.length() << '\n';
	return 0;
}
