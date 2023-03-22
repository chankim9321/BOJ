#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
int map[21][21] = {{0,},};
int N;
int minimum=10e8;
int comb[21] = {0,};
int teamStart=0, teamLink=0;
// 코드 시나리오
	// 1. n명이서 두팀을 나눌 수 있는 조합을 찾는다. 나누어진 팀을 t라고 한다.
	// 2. t 에서 두명의 조합(전력)을 구해야 하므로 tC2를 한다.
	// 3. 2명으로 나누어진 조합 (m,n)을 map배열에서 찾아 총 합을 계산한다.
	// 4. 팀마다 나온 총합의 차가 가장 작은 수를 찾아 반환한다.

int getTeamPower(vector<int> &team){
	vector<int> dummy;
	int sum=0;
	for(int i=0; i<team.size(); i++){ // 조합을 구하기위한 더미데이터 초기화
		if(i >= team.size()-2) dummy.push_back(1);
		else dummy.push_back(0);
	}
	do{
		int i=0, j=0;
		for(int k=0; k<team.size(); k++){
			if(dummy[k]){
				if(i==0) i = team[k];
				else j = team[k];
			}
		}
		sum = sum + map[i][j] + map[j][i];
	} while(next_permutation(dummy.begin(), dummy.end()));
	return sum;
}
void getCombination(int next, int num){
	if(next == N/2){
		int arr[21];
		vector<int> teamStart;
		vector<int> teamLink;
		for(int i=0; i<N; i++){
			arr[i] = i+1;
		}
		for(int i=0; i<next; i++){
			arr[comb[i]-1] = 0;
			teamStart.push_back(comb[i]);
		}
		for(int i=0; i<N; i++){
			if(arr[i] != 0){
				teamLink.push_back(arr[i]);
			}
		}
		int test = min(abs(getTeamPower(teamStart) - getTeamPower(teamLink)), minimum);
		minimum = test;
		return;
	}
	for(int i=num; i<=N; i++){
		comb[next] = i;
		getCombination(next+1, i+1);
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
		}
	}
	getCombination(0,1);
	cout << minimum << '\n';
	return 0;
}

