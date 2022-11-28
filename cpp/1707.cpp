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
bool sol(Node vt[], bool visited[], int start, int vertex){
	queue<Node*> q;
	q.push(&vt[start]); 
	vt[start].team = 1; 
	while(!q.empty()){
		Node *present = q.front();
		visited[present->number] = true;
		q.pop();
		vector<Node*>::iterator iter;
		for(iter = present->link.begin(); iter != present->link.end(); iter++){
			Node* next = (*iter);
			if(!visited[next->number]){
				if(present->team == next->team){ // 현재 팀과 링크에 등록된 노드들의 팀 컬러가 같다면 이분그래프가 아니다.
					return false;
				}
				if(present->team == 1){ // 현재 노드가 red 팀이라면 다음 노드들은 blue가 되어야 함.
					next->team = 2;
					q.push(next);
				}
				else{ // 현재노드가 blue 라면 다음 노드들은 red가 되어야 함.
					next->team = 1;
					q.push(next);
				}
			}
		}
	}
	// 연결 그래프가 아닐 수 있으므로 방문하지 않은 점들에 한에서 다시 sol을 호출
	for(int i=1; i<=vertex; i++){
		if(!visited[i]){
			if(!sol(vt, visited, i, vertex)){
				return false;
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
		if(sol(vt, visited, 1, vertex)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		delete[] vt;
		delete[] visited;
	}
	return 0;
}
