#include <iostream>
#define AND &&
#define OR ||
#define MAX 1000
#define INF 100000000
using namespace std; 

int getMin(int a, int b){
	return a < b ? a : b;
}
int colors[MAX+1][3];	

int solution(int houses){
	for(int i=1; i<houses; i++){
		for(int j=0; j<3; j++){
			if(j == 0){
				int a = colors[i][j] + colors[i-1][1];
				int b = colors[i][j] + colors[i-1][2];
				colors[i][j] = getMin(a, b);
			}
			else if(j == 1){
				int a = colors[i][j] + colors[i-1][0];
				int b = colors[i][j] + colors[i-1][2];
				colors[i][j] = getMin(a, b);
			}
			else{
				int a = colors[i][j] + colors[i-1][0];
				int b = colors[i][j] + colors[i-1][1];
				colors[i][j] = getMin(a, b);
			}
		}
	}
	int a = colors[houses-1][0];
	int	b = getMin(colors[houses-1][1], colors[houses-1][2]);
	return getMin(a,b);
}

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int houses;
	cin >> houses;
	for(int i=0; i<houses; i++){
		cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
	}
	cout << solution(houses) << "\n";
	return 0;
}
