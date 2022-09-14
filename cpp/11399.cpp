#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	int people;
	cin >> people;
	vector<int> hps;
	do{
		int input;
		cin >> input;
		hps.push_back(input); 
	}while(getc(stdin)== ' ');
	sort(hps.begin(),hps.end());
	int a=0,sum=0;
	for(int j=0; j<people; j++){
		a=a+hps[j];
		sum+=a;	
	}
	cout << sum << endl;
}
