#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	while(!cin.eof()){
		int n;
		cin >> n;

		int cipher = 2;
		int answer;
		long long k = 1;
		while(1){
			k =	k*10 +1; 	 
			if(k % n == 0){
				answer = cipher;
				break;
			}
			else{
				cipher++;			
			}
		}
		cout << answer << '\n';
	}
	return 0;
}
