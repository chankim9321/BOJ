#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000
#define MAX_LENGTH 10001
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//init
	int scSize; // 숏컷 사이즈
	int hwSize; // 고속도로 사이즈
	cin >> scSize >> hwSize;

	vector<pair<int, int> > sc[MAX_LENGTH];
	for(int i=0; i<scSize; i++){
		int from, to, length;
		cin >> from >> to >> length;
		sc[to].push_back(make_pair(from, length)); 
	}
	// solution
	// 시작점은 0으로 고정
	vector<int> d(hwSize+1, INF);
	d[0] = 0;
	for(int i=1; i<=hwSize; i++){
		if(sc[i].size() == 0) d[i] = d[i-1]+1; // 지름길이 없다면 기존 도로로 가는 수밖에 없다.
		else{
			for(auto v:sc[i]){
				d[i] = min(d[i], min(d[i-1]+1, d[v.first] + v.second)); 
			}
		}
	}
	cout << d[hwSize] << '\n';
	return 0;
}

