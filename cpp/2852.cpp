#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int goal;
	cin >> goal;

	int team1Score = 0, team2Score = 0;
	int team1Time = 0, team1Seconds = 0;
	int team2Time = 0, team2Seconds = 0;
	int preWinMinute, preWinSeconds;
	string time;
	int team;
	for(int i=0; i<goal; i++){
		cin >> team >> time;

		// 현재 결과 필터링
		int slicingIdx = time.find(':');
		string strWinMinute = time.substr(0,slicingIdx);
		string strWinSeconds = time.substr(slicingIdx+1);
		if(strWinMinute[0] == '0') strWinMinute = strWinMinute.substr(1);
		if(strWinSeconds[0] == '0') strWinSeconds = strWinSeconds.substr(1);
		// 연산에 쓰일 최종 결과
		int winMinute = stoi(strWinMinute); 
		int winSeconds = stoi(strWinSeconds); 

		if(team1Score == team2Score){
			preWinMinute = winMinute;
			preWinSeconds = winSeconds;
		}
		if(team == 1) team1Score++;
		else team2Score++;
		if(team1Score == team2Score){
			if(team == 1){ // 1번팀이 득점에서 동점이라면 그전까진 2번팀이 이기고 있었다는 뜻.
				team2Time += winMinute - preWinMinute;
				team2Seconds += winSeconds - preWinSeconds;
				if(team2Seconds >= 60){
					team2Seconds %= 60;
					team2Time++;
				}
			}
			else if(team == 2){ // 2번팀이 득점해서 동점이라면 그전까진 1번팀이 이기고 있었다는 뜻.
				team1Time += winMinute - preWinMinute;
				team1Seconds += winSeconds - preWinSeconds;
				if(team1Seconds >= 60){
					team1Seconds %= 60;
					team1Time++;
				}
			}
		}
	}
	// 마지막 케이스 계산
	if(team1Score != team2Score){
		if(team2Score > team1Score){ 
			team2Time += 47 - preWinMinute;
			team2Seconds += 60 - preWinSeconds;
			if(team2Seconds >= 60){
				team2Seconds %= 60;
				team2Time++;
			}
		}
		else if(team2Score < team1Score){ 
			team1Time += 47 - preWinMinute;
			team1Seconds += 60 - preWinSeconds;
			if(team1Seconds >= 60){
				team1Seconds %= 60;
				team1Time++;
			}
		}
	}
	// 출력부
	string t1TimeResult = to_string(team1Time);
	string t1SecondsResult = to_string(team1Seconds);
	string t2TimeResult = to_string(team2Time);
	string t2SecondsResult = to_string(team2Seconds);
	if(t1TimeResult.length() == 1) t1TimeResult = '0' + t1TimeResult;
	if(t1SecondsResult.length() == 1) t1SecondsResult = '0' + t1SecondsResult;
	if(t2TimeResult.length() == 1) t2TimeResult = '0' + t2TimeResult;
	if(t2SecondsResult.length() == 1) t2SecondsResult = '0' + t2SecondsResult;
	cout << t1TimeResult << ":" << t1SecondsResult << '\n';
	cout << t2TimeResult << ":" << t2SecondsResult << '\n';
	return 0;
}
