#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin >> n >> k;
	int coins[n];
	int money[100001] = {0,};
	for(int i=0; i<n; i++){
		cin >> coins[i];
	}
	money[0] = 1;
	for(int i=0; i<n; i++){
		for(int j=coins[i]; j<=k; j++){
			money[j] = money[j] + money[j-coins[i]];
		}
	}
	cout << money[k] << '\n';
}
