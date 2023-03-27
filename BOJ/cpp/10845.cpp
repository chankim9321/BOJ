#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	queue<int> q;
	for(int i=0; i<n; i++){
		string cmd;
		int num;
		cin >> cmd;
		if(cmd == "push") {
			cin >> num;
			q.push(num);
		}
		else if(cmd == "front"){
			if(q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
			}
		}
		else if(cmd == "back"){
			queue<int> tmp = q;
			if(tmp.size() == 0){
				cout << -1 << '\n';
			}
			else if(tmp.size() > 1){
				while(tmp.size() > 1) tmp.pop();
				cout << tmp.front() << '\n';
			}
		}
		else if(cmd == "empty"){
			if(q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(cmd == "size"){
			cout << q.size() << '\n';
		}
		else if(cmd == "pop"){
			if(q.empty()) cout << -1 << '\n';
			else{
				cout << q.front() << '\n';
				q.pop();
			}
		}
	}
	return 0;
}
