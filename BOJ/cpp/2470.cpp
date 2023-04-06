#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int differ = INT_MAX;
int n;
pair<int, int> ans;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int left = 0, right = 1;
	while(left < right){
		int res = abs(v[left] + v[right]);
		if(differ > res){
			differ = res;
			ans.first = v[left];
			ans.second = v[right];
			right++;
		}
		else{
			left++;
		}
		if(right == n) break;
	}
	cout << ans.first << " " << ans.second << '\n';
	return 0;
}
