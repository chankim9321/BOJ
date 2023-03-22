#include <iostream>
#include <algorithm>
#define DEBUG_MODE 0
using namespace std;

class Human{
	public:
		int document;
		int interview;
};
int getSmaller(int a, int b){ return a > b ? b : a; }
bool cmp(Human a, Human b){	return a.document < b.document;}

int solution(Human arr[],int candidates,int interview_min, int document_min){
	int max_pass=0;
	for(int i=0; i<candidates; i++){
		if(interview_min > arr[i].interview || document_min > arr[i].document){
			max_pass++;
		}
		interview_min = getSmaller(interview_min, arr[i].interview);
		document_min = getSmaller(document_min, arr[i].document);
	}
	return max_pass;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int testCase;
	int result[testCase];
	int candidates;
	int document_min=9999999;
	int interview_min=9999999;
	cin >> testCase;
	for(int i=0; i<testCase; i++){
		cin >> candidates;
		Human* arr = new Human[candidates];	
		for(int j=0; j<candidates; j++){ // init
			cin >> arr[j].document >> arr[j].interview;	
			// 1등일때 나머지 성적을 최소만족 성적으로 등록
			if(arr[j].document == 1){ 
				interview_min = arr[j].interview;
			}
			if(arr[j].interview == 1){
				document_min = arr[j].document;
			}
		}
		sort(arr, arr+candidates,cmp); // 서류전형을 기준으로 정렬
		#if DEBUG_MODE
		cout << "--------------SORT-------------" << '\n';
		for(int k=0; k<candidates; k++){
			cout << arr[k].document << " " << arr[k].interview << '\n';
		}
		cout << "-------------------------------" << '\n';
		#endif
		cout << solution(arr, candidates, interview_min, document_min) << '\n';
		delete[] arr;
	}
	return 0;
}
