#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> result;
bool cmp(const string s1, const string s2){
	if(s1.length() != s2.length()){
		return s1.length() < s2.length();
	}
	else return s1.compare(s2) < 0;
}
void parseStr(string input){
	input += " ";
	string parsed = "";
	for(int i=0; i<input.length()-1; i++){
		if(input[i] >= '0' && input[i] <= '9'){
			parsed += input[i];
			if(input[i+1] < '0' || input[i+1] > '9'){
				while(parsed[0] == '0' && parsed.length() > 1){
					parsed.erase(0,1);
				}
				result.push_back(parsed);
			}
		}
		else{
			parsed = "";	
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string input;
		cin >> input;
		parseStr(input);
	}
	sort(result.begin(), result.end(), cmp);
	for(auto i : result){
		cout << i << '\n';
	}
}
