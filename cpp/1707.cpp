#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
	public:
		vector<Node*> link;
		int team;
		int number;
};
// 자신과 인접한 노드는 전부 다른 팀에 속해있어야 한다.
// team 1 = red, team 2 = blue, team 0 = nothing
bool sol(Node vt[], bool visited[]){
	queue<Node*> q;
	q.push(&vt[1]); // 1부터 스타트
	vt[1].team = 1;
	while(!q.empty()){
		Node *present = q.front();
		visited[present->number] = true;
		q.pop();
		vector<Node*>::iterator iter;
		for(iter = present->link.begin(); iter != present->link.end(); iter++){
			if(!visited[(*iter)->number]){
				if(present->team == (*iter)->team){ // 현재 팀과 링크에 등록된 노드들의 팀 컬러가 같다면 이분그래프가 아니다.
					return false;
				}
				if(present->team == 1){ // 현재 노드가 red 팀이라면 다음 노드들은 blue가 되어야 함.
					(*iter)->team = 2;
					q.push(*iter);
				}
				else{ // 현재노드가 blue 라면 다음 노드들은 red가 되어야 함.
					(*iter)->team = 1;
					q.push(*iter);
				}
			}
		}
	}
	return true;
}
// 자신과 인접한 노드는 전부 다른 팀에 속해있어야 한다.
// team 1 = red, team 2 = blue, team 0 = nothing
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testCase;
	cin >> testCase;
	for(int i=0; i<testCase; i++){
		int vertex, edge;
		cin >> vertex >> edge;
		Node* vt = new Node[vertex+1];
		bool *visited = new bool[vertex+1];
		for(int j=1; j<=edge; j++){
			vt[j].number = j;
			vt[j].team = 0;
		}
		for(int j=0; j<edge; j++){
			int from, to;
			cin >> from >> to;
			vt[from].link.push_back(&vt[to]);	
			vt[to].link.push_back(&vt[from]);
		}
		if(sol(vt, visited)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		delete[] vt;
		delete[] visited;
	}
	return 0;
}
