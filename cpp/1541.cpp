#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
using namespace std;

int main(int argc, char* argv[]){
	string input;
	getline(cin, input);
	int a=0,sum=0,result=0;
	queue<int> value;
	for(int i=0; i<input.length(); i++){
		if(input[i] == '-'){
			int number=atoi(input.substr(a,i-a).c_str()); // number
			sum+=number;
			value.push(sum);
			sum=0;
			a=i+1;
		}
		else if(input[i] == '+'){
			int number=atoi(input.substr(a,i-a).c_str());
			sum+=number;
			a=i+1;
		}
	}
	sum+=atoi(input.substr(a,input.length()-a).c_str()); // post fence problem
	value.push(sum);
	result=value.front();
	value.pop();
	while(!value.empty()){
		result-=value.front();
		value.pop();
	}
	cout << result;
	return 0;
}
