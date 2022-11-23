#include <iostream>
#define ll long long
#define endl '\n';

using namespace std;

ll A, B, C;
ll sol(ll A, ll B){
	if(B==1) return A%C;
	else{
		ll res = sol(A, B/2);
		res = res*res%C;
		if(B % 2 == 0){
			return res;
		}
		else{ 
			res = res*A%C;
			return res;
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;

	cout << sol(A,B) << endl;
	return 0;
}
