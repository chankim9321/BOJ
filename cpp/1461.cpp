#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, bag;
int minusIdx = 0;
vector<int> pos;
void init(){
	cin >> n >> bag;
	for(int i=0; i<n; i++){
		int book;
		cin >> book;
		pos.push_back(book);
		if(book < 0) minusIdx++;
	}
}
void sol(){
	sort(pos.begin(), pos.end());
	int result = 0;
	for(int i=n-1; i >= minusIdx; i -= bag){ // 양수 구간
		result += pos[i] * 2;		
	}
	for(int i=0; i < minusIdx; i += bag){
		result += abs(pos[i]) * 2;
	}
	result -= max(abs(pos[0]), abs(pos[n-1])); // 왕복값을 빼준다
	cout << result << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);

	init();
	sol();
}
