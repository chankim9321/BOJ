#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	while(!cin.eof()){
		int n;
		cin >> n;
		if(n == 1) {
			cout << 1 << '\n';
			continue;
		}
		int cipher = 2;
		int answer;
		unsigned long long int k = 1;
		while(1){
			k =	k*10 +1; 	 
			if(k % n == 0){
				answer = cipher;
				break;
			}
			else{ // n으로 모듈러 연산이 이루어 지지 않을 때
				k = k%n;
				cipher++;			
			}
		}
		cout << answer << '\n';
	}
	return 0;
}
