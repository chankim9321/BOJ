#include <iostream>
#include <cmath>
#define MAX 2147483647;
#define ll long long
#define endl '\n';

using namespace std;

int A, B, C;
ll sol(int A, int B){
	if(B==1) return A;
	else{
		ll res = sol(A, B/2);
		if(B % 2 == 0){
			return res * res % C;
		}
		else return res * res * A % C;
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
