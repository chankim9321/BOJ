#include <iostream>
using namespace std;
int N,M;
int res[8] = {0,};

void sol(int start){
	if(start == M){
		for(int i=0; i<M; i++){
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}
	for(int i=0; i<N; i++){
		res[start] = i + 1;
		sol(start+1);
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	sol(0);
	return 0;
}
