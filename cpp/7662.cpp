#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		int t;
		cin >> t;
		priority_queue<long long> maxHeap;
		priority_queue<long long> minHeap;
		map<long long, long long> m;
		for(int j=0; j<t; j++){
			char command;
			cin >> command;
			if(command == 'D'){
				int select;
				cin >> select;
				if(select == 1){ // 최대힙에서 제거	
					while(!maxHeap.empty() && m[maxHeap.top()] == 0){ // 이미 최소힙에서 삭제된 값이라면
						maxHeap.pop(); // 제거
					}
					if(!maxHeap.empty()){
						m[maxHeap.top()]--; // 제거한 값은 항상 false
						maxHeap.pop();
					}
				}
				else if(select == -1){ // 최소힙에서 제거
					while(!minHeap.empty() && m[-minHeap.top()] == 0){
						minHeap.pop();
						if(minHeap.empty()) break;
					}
					if(!minHeap.empty()){
						m[-minHeap.top()]--;
						minHeap.pop();
					}
				}
			}
			else if(command == 'I'){
				long long data;
				cin >> data;
				maxHeap.push(data);
				minHeap.push(-data);
				if(m.find(data) == m.end()){
					m.insert({data, 1});
				}
				else{
					m[data]++;
				}
			}
		}
		while(!maxHeap.empty() && m[maxHeap.top()] == 0){
			maxHeap.pop();
		}
		while(!minHeap.empty() && m[-minHeap.top()] == 0){
			minHeap.pop();
		}
		if(!maxHeap.empty() && !minHeap.empty()){
			cout << maxHeap.top() << " " << -minHeap.top() << '\n';
		}
		else cout << "EMPTY" << '\n';
	}
	return 0;
}
