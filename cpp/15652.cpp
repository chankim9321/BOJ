#include <iostream>
using namespace std;
int N,M;
int res[8] = {0,};

void sol(int start, int num){
	if(start == M){
		for(int i=0; i<M; i++){
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}
	for(int i=num; i<=N; i++){
		res[start] = i;
		sol(start+1, i);
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	sol(0, 1);
	return 0;
}
