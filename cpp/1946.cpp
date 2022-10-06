#include <iostream>
using namespace std;
class Human{
	public:
		int document;
		int interview;
};
int getSmaller(int a, int b){ return a > b ? b : a; }
int solution(Human arr[],int candidates){
	int max_pass=0;
	for(int i=0; i<candidates; i++){
		int top_grade = getSmaller(arr[i].document, arr[i].interview); 	
		if(top_grade == arr[i].document){ // 서류전형이 높은 등수일 때
			bool is_passed = true;
			for(int k=0; k<candidates; k++){
				if(arr[k].document < top_grade){
					if(arr[k].interview > arr[i].interview) continue;
					else{
						is_passed = false;
						break;
					}
				}
			}
			if(is_passed) max_pass++;
		}
		else { // 면접전형이 높은 등수일 때
			bool is_passed = true;
			for(int k=0; k<candidates; k++){
				if(arr[k].interview < top_grade){ // 자기자신보다 높은 사람의 성적과 비교
					if(arr[k].document > arr[i].document) continue; // 서류전형이 자기보다 낮다면 반복문 계속 진행
					else{
						is_passed = false;
						break; // 서류전형이 자기보다 높다면 탈락
					}
				}
			}
			if(is_passed) max_pass++;
		}
	}
	return max_pass;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int testCase;
	int result[testCase];
	int candidates;
	cin >> testCase;
	for(int i=0; i<testCase; i++){
		cin >> candidates;
		Human* arr = new Human[candidates];	
		for(int j=0; j<candidates; j++){
			cin >> arr[j].document >> arr[j].interview;	
		}
		cout << solution(arr, candidates) << '\n';
		delete[] arr;
	}
	return 0;
}
