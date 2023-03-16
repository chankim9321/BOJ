#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}
int getGcd(int deco_1, int deco_2){
	int result;
	if(deco_1 > deco_2){
		result = gcd(deco_1, deco_2);
	}
	else if(deco_1 < deco_2){
		result = gcd(deco_2, deco_1);	
	}
	else result = deco_1;
	return result;
}
void sol(){
	// 분수의 합을 구하는 과정
	int numer_1, deco_1;
	int numer_2, deco_2;	
	cin >> numer_1 >> deco_1;
	cin >> numer_2 >> deco_2;
	int deco = (deco_1 * deco_2) / getGcd(deco_1, deco_2);
	numer_1 = numer_1 * (deco/deco_1);
	numer_2 = numer_2 * (deco/deco_2);
	int numer = numer_1 + numer_2;
	// 기약분수로 만드는 과정
	int divisor = getGcd(numer, deco);
	while(divisor != 1){
		numer /= divisor;		
		deco /= divisor;
		divisor = getGcd(numer, deco);
	}
	cout << numer << " " << deco << '\n';
	return;
}
int main(int argc, char* argv[]){
	sol();
	return 0;
}
