#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int dz[2] = {1, -1};

int main(int argc, char* argv[]){
	// init
	int M,N,H;
	bool is_done = true;
	cin >> M >> N >> H;
	vector<vector<vector<int> > > farm(H+2, vector<vector<int> >(N+2, vector<int>(M+2, -1))); // 3차원 배열
	queue<vector<int> > q; // 3차원 배열의 인덱스를 저장하는 큐
	for(int i=1; i<H+1; i++){
		for(int j=1; j<N+1; j++){
			for(int k=1; k<M+1; k++){
				cin >> farm[i][j][k];
				if(farm[i][j][k]) { // 익은 토마토라면 bfs에서 시작점으로 잡아야 하므로 큐에 삽입한다.
					vector<int> v;
					v.push_back(i);
					v.push_back(j);
					v.push_back(k);
					q.push(v);
				}
				if(farm[i][j][k] == 0){
					is_done = false;
				}
			}
		}
	}
	// solution
	int all_cnt = 0; // 정답값
	int cnt = q.size();	
	while(!q.empty()){
		if(is_done) break; // 안익은 토마토가 하나도 없다면
		vector<int> idx(q.front()); // 큐에 최상단에 존재하는 벡터 복사
		q.pop();
		// 현재 위치의 인덱스들
		int i = idx[0];
		int j = idx[1];
		int k = idx[2];
		// 동서남북 체크
		for(int d=0; d<4; d++){
			int next_j = j+dy[d];
			int next_k = j+dx[d];
			if(farm[i][next_j][next_k] == 0){ // 익지 않았다면
				farm[i][next_j][next_k] = 1;
				vector<int> next;
				next.push_back(i);
				next.push_back(next_j);
				next.push_back(next_k);
				q.push(next);
			}
		}
		// 위아래 체크
		for(int d=0; d<2; d++){
			int next_i = i+dz[d];
			if(farm[next_i][j][k] == 0){ // 익지 않았다면 
				farm[next_i][j][k] = 1;
				vector<int> next;
				next.push_back(next_i);
				next.push_back(j);
				next.push_back(k);
				q.push(next);
			}
		}
		cnt--;
		if(cnt == 0){ // 하나의 싸이클을 다 돌았으므로 all cnt값을 증가시킨다.
			all_cnt++;
			cnt = q.size();	// 큐에 삽입하면서 기록한 싸이클을 cnt에 넣는다.
		}
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

	cout << all_cnt << '\n';
	return 0;
}
