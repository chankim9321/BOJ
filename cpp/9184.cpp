#include <iostream>
#include <algorithm>
#define OR ||
#define AND &&
using namespace std;

int matrix[21][21][21];

int w(int a, int b, int c){
	if(a <= 0 OR b <=0 OR c <= 0) return 1;
	if(a > 20 OR b > 20 OR c > 20) return w(20,20,20);
	if(a < b AND b < c ) {
		if(matrix[a][b][c] != 0){
			return matrix[a][b][c];
		}
		else {
			matrix[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
			return matrix[a][b][c];
		}
	}
	else {
		if(matrix[a][b][c] != 0){
			return matrix[a][b][c];
		}
		else {
			matrix[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
			return matrix[a][b][c];
		}
	}
}
int main(int argc, char* argv[]){
	int a, b, c;
	fill(&matrix[0][0][0], &matrix[20][20][21], 0);
	cin >> a >> b >> c;
	cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c)  << "\n";
	return 0;
}
