#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_pair(vector<pair<int,int>> a,int testset){
	for(int i=0; i<testset; i++){
		cout << a[i].second << ","<< a[i].first << endl;
	}
}
int main(int argc, char* argv[]){	
	int testset;
	cin >> testset; //  input test case
	vector<pair<int,int>> a(testset);
	for(int i=0; i<testset; i++){
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(),a.end());
	int savetime=0,	answer=0;
	for(int i=0; i<testset; i++){
		if(savetime <= a[i].second){
			savetime=a[i].first;
			answer++;
		}
	}
	cout << answer << endl;
	return 0;
}
