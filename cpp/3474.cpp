#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for(int i=0; i<tc; i++){
		int n;
		cin >> n;
		int cnt = 0;	
		for(int k=5; k<=n; k*=5){
			cnt += n/k;
		}
		cout << cnt << '\n';
	}
	return 0;
}
