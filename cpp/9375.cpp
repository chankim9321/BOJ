#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int getClothesCombination(map<string, vector<string>>& clothes){
	map<string, vector<string>>::iterator start = clothes.begin();	
	map<string, vector<string>>::iterator end = clothes.end();	
	int result = clothes[start->first].size()+1;
	start++;
	for(; start != end; start++){
		result *= (clothes[start->first].size()+1);
	}
	return --result;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ts;
	cin >> ts;

	for(int i=0; i<ts; i++){
		int dress;
		cin >> dress;
		if(dress == 0){
			cout << 0 << '\n';
			continue;
		}
		map<string, vector<string>> clothes;
		for(int j=0; j<dress; j++){
			string name, type;
			cin >> name >> type;
			clothes[type].push_back(name);
		}
		int result = getClothesCombination(clothes);
		cout << result << '\n';
	}
}
