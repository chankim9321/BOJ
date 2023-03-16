#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LinkedList{
	public:
		char c;
		LinkedList* left;
		LinkedList* right;
};
LinkedList* str;
LinkedList* cursur;
LinkedList* start;
int n;

void callCommands(int strSize){ 
	// 커서는 현재 문자열의 마지막을 가르킴.
	for(int i=0; i<n; i++){
		char command;
		cin >> command;
		if(command == 'L'){ // 커서 왼쪽으로 이동
			if(cursur->left != NULL) cursur = cursur->left;
		}
		else if(command == 'D'){ // 커서 오른쪽으로 이동
			if(cursur->right != NULL) cursur = cursur->right;
		}
		else if(command == 'B'){ // 커서 왼쪽 삭제
			if(cursur->left != NULL){
				LinkedList* temp = cursur;
				cursur->left->right = cursur->right;
				if(cursur->right != NULL){
					cursur->right->left = cursur->left; 
				}
				cursur = cursur->left;
			}
		}
		else if(command == 'P'){ // 커서 왼쪽에 추가
			char newChar;
			cin >> newChar;
			LinkedList* insert = new LinkedList;
			insert->c = newChar;
			insert->left = cursur;
			insert->right = cursur->right;
			cursur->right = insert;
			cursur = insert;
		}
	}
	// 출력
	for(LinkedList* it = start; it != NULL; it = it->right){
		if(it->c == ' ') continue;
		cout << it->c;
	}
	cout << '\n';
}

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	getline(cin, input);
	input = " " + input; // 앞에 공백하나추가(fencePost Problem 해결)
	// 문자열을 링크드리스트로 변환
	str = new LinkedList[input.size()];
	for(int i=0; i<input.size(); i++){
		str[i].c = input[i];
		if(i == 0){
			start = &str[i];
			str[i].left = NULL;	
			str[i].right = &str[i+1];
		}
		else if(i == input.size()-1){
			str[i].right = NULL;
			str[i].left = &str[i-1];
			cursur = &str[i]; // 첫 커서는 맨 마지막 원소를 가르킴
		}
		else{
			str[i].left = &str[i-1];
			str[i].right = &str[i+1];
		}
	}
	cin >> n;
	callCommands(input.size());		
	return 0;
}
