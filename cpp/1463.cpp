#include <iostream>
#define AND &&
#define OR ||
using namespace std;
int callNumber=0;

int solution(int number){
	if(number == 1) return callNumber;
	if( (number -1) % 3 == 0) {
		callNumber++;
		return solution(number-1);
	}
	else if(number % 3 == 0){
		callNumber++;
		return solution(number/3);
	}
	else if(number % 2 == 0){
		callNumber++;
		return solution(number/2);
	}
	else{
		callNumber++;
		return solution(number-1);
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int number;
	cin >> number;
	cout << solution(number) << "\n";
	return 0;
}
