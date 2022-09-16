#include <iostream>
#include <algorithm>
#define OR ||
#define AND &&
using namespace std;

int matrix[21][21][21];

int w(int a, int b, int c){
	if(a <= 0 OR b <=0 OR c <= 0) return 1; // 하나라도 0 이하라면 1 반환
	if(a > 20 OR b > 20 OR c > 20) return w(20,20,20); // 하나라도 20을 초과하는 파라미터라면 20으로 변환하여 호출
	if(matrix[a][b][c] != 0){
		return matrix[a][b][c];
	}
	if(a<b AND b<c){
		return matrix[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
	}
	return matrix[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
}
int main(int argc, char* argv[]){
	int a, b, c;
	fill(&matrix[0][0][0], &matrix[20][20][21], 0);
	while(true){
		cin >> a >> b >> c;
		if(a == -1 AND b == -1 AND c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c)  << "\n";
	}
	return 0;
}
