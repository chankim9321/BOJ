#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char* argv[]){

	int goal;
	cin >> goal;
	int score1 = 0, score2 = 0;
	int team1 = 0, team2 = 0;
	int pre = 0;
	for(int i=0; i<goal; i++){
		int team;
		int min, sec;
		cin >> team;
		scanf("%2d:%2d", &min, &sec);
		if(score1 > score2){
			team1 += min * 60 + sec - pre;
		}
		else if(score1 < score2){
			team2 += min * 60 + sec - pre;
		}
		if(team == 1){
			score1++;
		}
		else if(team == 2){
			score2++;
		}
		pre = min * 60 + sec;
	}
	if(score1 > score2){
		team1 += 2880 - pre;
	}
	else if(score1 < score2){
		team2 += 2880 - pre;
	}
	printf("%02d:%02d\n",team1 / 60, team1 % 60);
	printf("%02d:%02d\n",team2 / 60, team2 % 60);
	return 0;
}
