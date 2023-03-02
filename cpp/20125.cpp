#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> board;
int n;
pair<int, int> heart;
pair<int, int> waistPos;
void dbf(){ while(getchar() != '\n'); }
void init(){
	cin >> n;
	board.resize(n+1, vector<char> (n+1, ' '));
	dbf();
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%1c", &board[i][j]);
		}
		dbf();
	}
}
int find(pair<int, int> pos, int len, int part){
	if(pos.first > n || pos.second > n) return len;
	if(part == 1) { // 오른 팔
		if(board[pos.first][pos.second] == '*'){
			return find({pos.first,pos.second + 1}, len + 1, part);
		}
		else return len;
	}
	else if(part == 2) { // 왼팔
		if(board[pos.first][pos.second] == '*'){
			return find({pos.first,pos.second - 1}, len + 1, part);
		}
		else return len;
	}
	else if(part == 3) { // 허리
		if(board[pos.first][pos.second] == '*'){
			return find({pos.first + 1,pos.second}, len + 1, part);
		}
		else{
			waistPos = {pos.first-1, pos.second};
			return len;
		}
	}
	else if(part == 4) { // 오른 다리
		if(board[pos.first][pos.second] == '*'){
			return find({pos.first + 1, pos.second}, len+1, part);
		}
		else return len;
	}
	else if(part == 5) { // 왼 다리
		if(board[pos.first][pos.second] == '*'){
			return find({pos.first + 1, pos.second}, len+1, part);
		}
		else return len;
	}
	return len;
}
void sol() {
	int leftArm;
	int rightArm;
	int rightLeg;
	int leftLeg;
	int waist;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(board[i][j] == '*' && board[i-1][j] == '*' && board[i][j+1] == '*' && board[i][j-1] == '*' && board[i+1][j] == '*'){
				heart = {i,j};
				rightArm = find({i, j+1}, 0, 1);		
				leftArm = find({i, j-1}, 0, 2);
				waist = find({i+1, j}, 0, 3); 
				rightLeg = find({waistPos.first + 1, waistPos.second + 1}, 0, 4);
				leftLeg = find({waistPos.first + 1, waistPos.second - 1}, 0, 5);
			}
		}
	}
	cout << heart.first << " " << heart.second << '\n';
	cout << leftArm << " " << rightArm << " " << waist << " " << leftLeg << " " << rightLeg << '\n';
}
int main(int argc, char* argv[]){
	init();
	sol();

	return 0;
}
