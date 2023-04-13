#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

void init(){
	cin >> n;
	v.resize(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
}
void sol(){
	sort(v.begin(), v.end());
	int goodNumbers = 0;
	for(int i=0; i<n; i++){
		int num = v[i];
		int p1 = 0;
		int p2 = 1;
		while(p1 < p2){
			if(p1 == i){
				p1++;
				if(p1 == p2) p2++;
			}
			if(p2 == i){
				p2++;
			}
			if(v[p1] + v[p2] > num) break;
			else if(v[p1] + v[p2] < num){
				if(p2 + 1 < n){ // p2 을 우선으로 움직임
					p2++;
				}
				else if(p1 + 1 < p2) { // p2 가 더이상 움직이지 못하면 p1을 움직임
					p1++;
				}
				else break; // 둘다 더이상 움직이지 못하면 좋은 숫자가 아니므로 break
			}
			else{
				goodNumbers++;
				break;
			}
		}
	}
	cout << goodNumbers << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	sol();
	
	return 0;
}
