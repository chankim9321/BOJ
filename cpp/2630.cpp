#include <iostream>
#include <vector>
using namespace std;
int result1 = 0;
int result0 = 0;
void sol(int startY, int startX, int height, int width, vector<vector<int>>& matrix){
	bool flag0 = false;
	bool flag1 = false;
	bool isDivided = false;
	for(int i=startY; i<height; i++){
		for(int j=startX; j<width; j++){
			if(matrix[i][j] == 0) flag0 = true;
			else flag1 = true;
			if(flag0 == true && flag1 == true){ // 1과 0이 동시에 존재한다면
				isDivided = true;
				sol(startY, startX, (startY + height)/2, (startX + width)/2, matrix); // 1
				sol(startY, (startX + width)/2, (startY + height)/2, width, matrix); // 2
				sol((startY + height)/2, startX, height, (startX + width)/2, matrix); // 3
				sol((startY + height)/2, (startX + width)/2, height, width, matrix); // 4
			}
			if(isDivided) return;
		}
	}
	if(flag1 == true && flag0 == false) result1++;
	else if(flag1 == false && flag0 == true) result0++;
	else{
		cout << "Exception Occured!" << '\n';
		cout << "Exception Detailed: " << '\n';
		cout << "StartY = " << startY << ", StartX = " << startX << '\n';
		cout << "Height = " << height << ", Width = " << width << '\n';
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size;
	cin >> size;
	vector<vector<int>> matrix(size, vector<int>(size, 0));
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			int value;
			cin >> value;
			matrix[i][j] = value;
		}
	}
	sol(0, 0, size, size, matrix);
	cout << result0 << '\n' << result1 << '\n';
	return 0;
}
