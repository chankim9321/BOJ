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

	bool plus = false, minus = false;
	cin >> n;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		v.push_back(num);
		if(num > 0) plus = true;
		if(num < 0) minus = true;
	}
	sort(v.begin(), v.end());
	if(plus && !minus){
		ans.first = v[0];
		ans.second = v[1];
	}
	else if(!plus && minus){
		ans.first = v[n-2];
		ans.second = v[n-1];
	}
	else{
		int left = 0;
		int right = n-1;
		while(left < right){
			int res = v[left] + v[right];
			if(differ > abs(res)) {
				ans.first = v[left];
				ans.second = v[right];
				differ = abs(res);
			}
			if(res < 0){
				left++;
			}
			else if(res > 0){
				right--;
			}
			else{
				ans.first = v[left];
				ans.second = v[right];
				break;
			}
		}
	}
	cout << ans.first << " " << ans.second << '\n';
	return 0;
}
