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
	int ans = 10e8 * 2 + 1;
	sort(v.begin(), v.end());
	int left = 0, right = 0;
	while(left < n && right < n){
		if(v[right] - v[left] >= m){
			ans = min(ans, v[right] - v[left]);
			left++;
		}
		else if(v[right] - v[left] < m){
			right++;
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
