#include <iostream>
#define AND &&
#define OR ||
using namespace std;
int solution(int number){
	int callNumber=0;
	do{
		if(number % 2 != 0 AND number % 3 != 0){
			number--;
			callNumber++;
		}
		else if(number % 3 != 0){
			if( (number-1)/3 < (number/2)-1){  // D(n+2)의 결과 비교
				number--;
				callNumber++;
			}
			else{
				number/=2;
				callNumber++;
			}
		}
		else{
			number/=3;
			callNumber++;
		}
	}while(number != 1);
	return callNumber;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int number;
	cin >> number;
	cout << solution(number) << "\n";
	return 0;
}
