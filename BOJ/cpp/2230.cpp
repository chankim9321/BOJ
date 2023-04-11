#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
void init(){
	cin >> n >> m;
	v.resize(n);	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
}
void sol(){
	if(n == 1){
		cout << 0 << '\n';
		return;
	}
	int ans = 10e8;
	sort(v.begin(), v.end());
	int p1 = 0, p2 = 1;
	while(p2 < n){
		if(v[p2] - v[p1] >= m){
			ans = min(ans, v[p2] - v[p1]);
			p1++;
		}
		else if(v[p2] - v[p1] < m){
			p2++;
		}
	}
	cout << ans << '\n';
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	sol();

	return 0;
}
