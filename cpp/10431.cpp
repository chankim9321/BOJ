#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	vector<pair<int, int>> result;
	for(int i=0; i<tc; i++){
		int changed = 0;
		int n;
		cin >> n;
		deque<int> line;
		for(int i=0; i<20; i++){
			int height;
			cin >> height;
			line.push_back(height);
		}
		while(1){
			bool flag = false;
			int value = line.back();
			line.pop_back();
			for(int j=line.size()-1; j >= 0; j--){
				if(line[j] > value){
					line.push_front(value);	
					changed++;
					break;
				}
			}
			if(line.size() == 1) break;
		}
		result.push_back({n, changed});
	}
	for(auto res : result){
		cout << res.first << " " << res.second << '\n';
	}
	return 0;
}
