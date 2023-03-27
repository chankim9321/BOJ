#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	// fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// init
	int size;
	cin >> size;
	vector<pair<int, int> > pole;
	for(int i=0; i<size; i++){
		int a, b;
		cin >> a >> b;
		pole.push_back(make_pair(a, b));
	}

	// solution
	sort(pole.begin(), pole.end());
	vector<int> seq; // 두번째 전봇대의 수를 수열로 나타낸 것
	for(int i=0; i<size; i++){
		seq.push_back(pole[i].second);	
	}
	int dp[size];	
	fill_n(dp, size, 1);
	int maximum = 1;
	for(int i=1; i<size; i++){
		for(int j=i-1; j>=0; j--){
			if(seq[i] > seq[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maximum = max(dp[i], maximum);
	}
	cout << size - maximum << '\n';
	return 0;
}

