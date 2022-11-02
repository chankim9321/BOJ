#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//init
	int item, weightLimit;
	cin >> item >> weightLimit;
	vector<pair<int, int> > items;
	items.push_back(make_pair(0, 0)); // dummy items
	for(int i=0; i<item; i++){
		int weight, value;
		cin >> weight >> value;
		items.push_back(make_pair(weight, value));
	}
	sort(items.begin(), items.end()); // weight 기준으로 정렬

	// solution
	// DP 배열의 세로축은 아이템의 수, 가로축은 무게한도를 의미한다.
	// 정답값은 DP[item][weightLimit] 에 존재한다. 
	
	int DP[item+1][weightLimit];
	fill(DP[0], DP[0]+item*weightLimit, 0);
	for(int i=1; i<=item; i++){ // 아이템이 1개 이상인 상태부터 시작
		for(int j=1; j<=weightLimit; j++){ // 아이템의 갯수가 정해졌을 떄, 무게한도 1이상 부터 시작
			int preBag = DP[i-1][j]; // 이전 싸이클의 가방 내용 (물건이 없는 경우)
			int itemValue = items[i].second;
			int itemWeight = items[i].first;
			if(j < itemWeight){ // 현재 무게한도가 새로운 아이템의 무게보다 낮은 경우는 아이템을 넣을 수 없으므로
				DP[i][j] = preBag;
			}
			else{	
				int preItem = DP[i-1][j-itemWeight];
				int newBag = preItem + itemValue;
				DP[i][j] = max(preBag, newBag);	
			}
		//	cout << DP[i][j] << " - ";
		}
		//cout << '\n';
	}
	cout << DP[item][weightLimit] << '\n';

	return 0;
}
