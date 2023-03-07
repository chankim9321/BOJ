#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	map<string, int> dict;
	
	double all = 0;
	while(1){
		string tree;
		if(getline(cin, tree)){
			for(auto i = dict.begin(); i != dict.end(); i++){
				double percent = (i->second * 100) / all;
				cout << fixed;
				cout.precision(4);
				cout << i->first << " " << percent << '\n';
			}
			break;
		}
		all++;
		if(dict.find(tree) != dict.end()){
			dict[tree]++;
		}
		else {
			dict.insert({tree, 1});
		}
	}	
	return 0;
}
