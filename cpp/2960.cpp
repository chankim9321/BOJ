#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<bool> v;
void init(){
	cin >> n >> k;
	v.resize(n+1, true);
}
void sol(){
	int number = 0;
	for(int i=2; i<=n; i++){
		if(!v[i]) continue;
		for(int j=i; j<=n; j = j + i){
			if(v[j]){
				v[j] = false;
				number++;	
				if(number == k){
					cout << j << '\n';
					return;
				}
			}
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	sol();
	return 0;
}
