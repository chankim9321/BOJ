#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int F,S,G,U,D;

void sol(int next_pos[], int cnt[], bool visited[]){
	queue<pair<int, int>> q;
	q.push({S, 0});
	visited[S] = true;
	while(!q.empty()){
		pair<int, int> present = q.front();
		q.pop();
		cnt[present.first] = min(cnt[present.first], present.second); // update
		for(int i=0; i<2; i++){
			int next = present.first + next_pos[i];
			if(next <= F && next > 0){
				if(!visited[next]){
					visited[next] = true;
					q.push({next, present.second +1});
				}
			}
		}
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// F = 건물 층수
	// S = 강호가 있는 층
	// G = 목적지
	// U = U층 만큼 올라가는 버튼
	// D = D층 만큼 내려가는 버튼
	cin >> F >> S >> G >> U >> D;
	D = -D;
	int next_pos[2] = {U, D};
	int cnt[F+1];
	bool visited[F+1];
	fill_n(&cnt[0], F+1, 1000001);
	fill_n(&visited[0], F+1, false);
	sol(next_pos, cnt, visited);
	if(cnt[G] != 1000001){
		cout << cnt[G] << '\n';
	}
	else cout << "use the stairs" << '\n';
	return 0;
}
