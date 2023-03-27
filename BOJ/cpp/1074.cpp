#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int r,c;
int answer = 0;
void sol(int startY, int startX, int size){
	if(r == startY && c == startX){
		cout << answer << '\n';
	}
	//  탐색좌표가 현재 함수 내 사분면안에 존재할때
	// 방문순서가 중요하다.
	else if(r >= startY && r < startY + size && c >= startX && c < startX + size ){
		sol(startY, startX, size/2); // 1 
		sol(startY, startX + size/2, size/2); // 2
		sol(startY + size/2, startX, size/2); // 3
		sol(startY + size/2, startX + size/2, size/2);
	}
	else{ // 탐색값을 누적으로 합산
		answer += size*size;
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n >> r >> c;
	sol(0,0,pow(2,n));
	return 0;
}
