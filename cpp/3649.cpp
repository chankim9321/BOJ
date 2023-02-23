#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int holeWidth, lego;
vector<int> legos;
void sol(){
	vector<pair<int, int>> result;
	sort(legos.begin(), legos.end());
	for(int i=0; i<legos.size(); i++){
		cout << legos[i] << " ";
	}
	cout << '\n';
	int start = 0, end = legos.size()-1;	
	while(start < end){
		if(legos[start] + legos[end] == holeWidth){
			result.push_back({legos[start], legos[end]});
			start++;
			end--;
		}else if (legos[start] + legos[end] < holeWidth){
			start++;
		}else if (legos[start] + legos[end] > holeWidth){
			end--;
		}
	}
	if(result.size() == 0){
		cout << "danger" << '\n';
	}else{
		int maxValue = -1;
		int answer_1, answer_2;
		for(int i=0; i<result.size(); i++){
			int value = abs(result[i].first - result[i].second);
			if(maxValue < value){
				maxValue = value;
				answer_1 = result[i].first;
				answer_2 = result[i].second;
			}
		}
		cout << "yes " << answer_1 << " " << answer_2 << '\n';
	}
	legos.resize(0);	
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while(1){
		cin >> holeWidth;
		if(cin.eof() == true) break;
		holeWidth *= 10000000;
		cin >> lego;
		legos.resize(lego, 0);
		for(int i=0; i<lego; i++){
			cin >> legos[i];
		}
		sol();
	}
	return 0;
}
