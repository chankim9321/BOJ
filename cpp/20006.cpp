#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

bool sortByName(pair<int, char> &a, pair<int, char> &b){
	return (a.second < b.second);
}
int main(int argc, char* argv[]){
	int players, rooms;
	cin >> players >> rooms;
	list<pair<vector<pair<int, char> >, int > > roomList; // ( 방의 인원, 방 주인 레벨) 을 리스트로 저장

	// 첫번째 방 생성
	int l;
	char n;
	cin >> l >> n;
	vector<pair<int, char> > v;
	v.push_back({l, n});
	roomList.push_back({v,l});
	list<pair<vector<pair<int, char> >, int> > ::iterator iter;
	for(int i=1; i<players; i++){
		bool is_success = false;
		int level;
		char name;
		cin >> level >> name;
		for(iter=roomList.begin(); iter!=roomList.end(); iter++){
			int levelRange = iter->second;
			int roomPlayerSize = iter->first.size();
			if(levelRange + 10 >= level && levelRange - 10 <= level && roomPlayerSize < rooms){ // 입력받은 레벨내 허용되는 방이 존재한다면
				iter->first.push_back({level, name});	
				is_success = true;
				break;
			}
		}
		if(!is_success){
			vector<pair<int, char> > nv; // 방 생성
			nv.push_back({level, name}); // 방 인원 추가
			roomList.push_back({nv, level}); // 생성된 방과 적정레벨을 방 목록에 추가
		}
	}
	// 출력부
	for(iter = roomList.begin(); iter != roomList.end(); iter++){
		int roomPlayerSize = iter->first.size();
		vector<pair<int, char> > roomInfo(iter->first);
		sort(roomInfo.begin(), roomInfo.end(), sortByName);
		if(roomPlayerSize < 5){
			cout << "Waiting!\n";
			for(int j=0; j<roomPlayerSize; j++){
				cout << roomInfo[j].first << " " << roomInfo[j].second << '\n';
			}
		}
		else{
			cout << "Started!\n";
			for(int j=0; j<roomPlayerSize; j++){
				cout << roomInfo[j].first << " " << roomInfo[j].second << '\n';
			}
		}
	}
	
	return 0;
}
