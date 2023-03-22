#include <iostream>
using namespace std;
int res[9] = {0,};
int N,M;

void printArr(){
	for(int i=0; i<M; i++){
		cout << res[i] << " ";
	}
	cout << '\n';
}
void sol(int depth, bool dupliCheck[]){
	if(M == depth) {
		printArr();
		return;
	}
	for(int i=1; i<=N; i++){
		if(!dupliCheck[i]){
			dupliCheck[i] = true;
			res[depth] = i;
			sol(depth+1, dupliCheck);
			dupliCheck[i] = false;
		}
	}
}
int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	bool dupliCheck[9] = {false, };
	sol(0, dupliCheck);
	return 0;
}
