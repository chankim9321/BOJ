#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> result;
void parseStr(string input){
	input += " ";
	string parsed = "";
	for(int i=0; i<input.length(); i++){
		if(input[i] >= '0' && input[i] <= '9'){
			parsed += input[i];
			if(input[i+1] < '0' || input[i+1] > '9'){
				while(parsed[0] == '0' && parsed.length() > 1){
					parsed.erase(0,1);
				}
				result.push_back(stoi(parsed));
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
	sort(result.begin(), result.end());
	for(auto i : result){
		cout << i << '\n';
	}
}
