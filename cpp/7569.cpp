#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define DEBUG_MODE 0
using namespace std;

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(int argc, char* argv[]){
	// fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// init
	int M,N,H;
	bool isDone = true;
	cin >> M >> N >> H;
	int farm[103][103][103];
	fill_n(&farm[0][0][0], 103*103*103, -1);
	queue<vector<int> > q; // 3차원 배열의 인덱스를 저장하는 큐
	for(int i=1; i<H+1; i++){
		for(int j=1; j<N+1; j++){
			for(int k=1; k<M+1; k++){
				cin >> farm[i][j][k];
				if(farm[i][j][k] == 1) { // 익은 토마토라면 bfs에서 시작점으로 잡아야 하므로 큐에 삽입한다.
					vector<int> v;
					v.push_back(i);
					v.push_back(j);
					v.push_back(k);
					q.push(v);
				}
				if(farm[i][j][k] == 0){ // 익지 않은 토마토가 하나라도 존재한다면 
					isDone = false;
				}
			}
		}
	}
	// solution
	int all_cnt = 0; // 정답값
	int cnt = q.size();	 // 한번의 싸이클
	while(!q.empty()){
		if(isDone) break; // 초기화 단계에서 안익은 토마토가 하나도 없다면
		vector<int> idx(q.front()); // 큐에 최상단에 존재하는 벡터 복사
		q.pop();
		// 현재 위치의 인덱스들
		int i = idx[0];
		int j = idx[1];
		int k = idx[2];
		//cout << "현재위치: {" << i << ", " << j << ", " << k << "}" << "값 :" << farm[i][j][k] << '\n';
		// 동서남북, 위 아래 체크
		for(int d=0; d<6; d++){
			int next_i = i+dz[d];
			int next_j = j+dy[d];
			int next_k = k+dx[d];
			if(farm[next_i][next_j][next_k] == 0){ // 익지 않았다면
		//		cout << "해당 좌표: {" << next_i << ", " << next_j << ", " << next_k << "} " << "값 :" << farm[next_i][next_j][next_k] << '\n';
				farm[next_i][next_j][next_k] = 1;
				vector<int> next;
				next.push_back(next_i);
				next.push_back(next_j);
				next.push_back(next_k);
				q.push(next);
			}
		}
		cnt--;
		if(cnt == 0){ // 1일이 지났을 떄
			all_cnt++;
			cnt = q.size();	// 큐에 삽입하면서 기록한 싸이클을 cnt에 넣는다.
		}
	}
	if(!isDone){
		all_cnt = all_cnt -1;
	}
	for(int i=1; i<H+1; i++){
		for(int j=1; j<N+1; j++){
			for(int k=1; k<M+1; k++){
				if(farm[i][j][k] == 0){ // 안익은 토마토가 발견된다면
					all_cnt = -1;
				}
			}
		}
	}
	cout << all_cnt << '\n'; // 다 익더라도 while문을 한번 더 돌기때문에 -1 해준다.
	return 0;
}
