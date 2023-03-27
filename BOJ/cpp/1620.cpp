#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, string> dict;

	for(int i=1; i<=n; i++){
		string input;
		cin >> input;
		dict.insert({input, to_string(i)});	
		dict.insert({to_string(i), input});
	}
	for(int i=0; i<m; i++){
		string input;
		cin >> input;
		cout << dict[input] << '\n';	
	}
	return 0;
}
