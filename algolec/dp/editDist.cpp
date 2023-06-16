#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s1 = "strong";
string s2 = "stone";

int m = s1.length();
int n = s2.length();
void editDistance(vector<vector<int>> &dpTable){
	for(int i=0; i<m; i++){
		dpTable[i][0] = i;
	}
	for(int j=0; j<m; j++){
		dpTable[0][j] = j;
	}
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			dpTable[i][j] = min(dpTable[i][j-1]+1, dpTable[i-1][j]+1);
			if(s1[i] == s2[j]){
				dpTable[i][j] = min(dpTable[i][j], dpTable[i-1][j-1]);
			}
			else dpTable[i][j] = min(dpTable[i][j], dpTable[i-1][j-1] + 1);
		}
	}
}
int main(int argc, char* argv[]){
	vector<vector<int>> dpTable(m, vector<int>(n,0));
	editDistance(dpTable);
	
	cout << dpTable[m-1][n-1] << '\n';
	return 0;
}
