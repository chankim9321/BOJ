#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char* argv[]){
	int people;
	int leftPeople;
	cin >> people;
	int queue[people];
	fill_n(&queue[0], people, 0);
	for(int i=1; i<=people; i++){
		cin >> leftPeople; // 자기보다 큰 수만 세기 때문에 앞서 나온 숫자들은 신경 쓸 필요가 없다.
		for(int j=0; j<people; j++){
			if(leftPeople == 0 && queue[j] == 0){ // 왼쪽사람이 없고 자리가 비어있다면
				queue[j]=i;
				break;
			}
			else if(queue[j] == 0){ // 자리가 비어있을때 자신보다 키가 큰 사람이 있어야 하기때문에 자리차지 불가.
				leftPeople--;
			}
			else{}
		}
	}
	for(int i=0; i<people; i++){
		cout << queue[i] << " ";
	}
		cout << '\n';
	return 0;
}
