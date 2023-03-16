#include <iostream>
using namespace std;

int res[9]={0,};
int length;
int combination;
int dupliCheck[9] = {false, };

void printArr(){
	for(int i=0; i<combination; i++){
		cout << res[i] << " ";
	}
	cout << '\n';
}
void sol(int depth, int start){
	if(combination == depth){
		printArr();
		return;
	}
	for(int i=start; i<=length; i++){
		res[depth] = i;
		sol(depth+1, i+1);
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> length >> combination;

	sol(0,1);
	return 0;
}
