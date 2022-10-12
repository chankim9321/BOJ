#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Node{
	public:
		int id;
		vector<Node*> link;	
};
int bfs(int removed, Node* Tree, int vertex){
	int is_visited[vertex+1];
	fill_n(is_visited, vertex+1, 0);
	is_visited[removed] = 1;
	int cnt=0;
	for(int i=1; i<=vertex; i++){
		if(!is_visited[i]){
			queue<Node*> q;
			q.push(&Tree[i]);
			is_visited[i] = 1;
			while(!q.empty()){
				Node* root = q.front();
				q.pop();
				for(int i=0; i<root->link.size(); i++){
					int idx = root->link[i]->id;
					if(!is_visited[idx]){ // 다음 방문할 정점의 번호가 단절 대상이라면 방문 x
						is_visited[idx] = 1;
						q.push(root->link[i]);
					}
				}
			}
			cnt++;
		}
	}
	return cnt;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int vertex, query;
	cin >> vertex;
	// init
	Node* Tree = new Node[vertex+1];
	for(int i=1; i<vertex; i++){ // vertex-1 개 만큼의 간선을 입력받는다
		Tree[i].id = i;
		int from, to;
		cin >> from >> to;
		Tree[from].link.push_back(&Tree[to]);	
	}
	Tree[vertex].id = vertex;
	// init end
	cin >> query;
	for(int i=0; i<query; i++){
		int q, removed;
		cin >> q >> removed;
		if(q == 1){ // 단절점인지에 대한 질의
			int graphs = bfs(removed, Tree, vertex);	
			if(graphs > 1){
				cout << "yes" << '\n';
			}
			else{
				cout << "no" << '\n';
			}
		}
		else{ // 단절선인지에 대한 질의
			// 정점이 무조건 2개 이상이므로 어느 간선을 자르던간에 단절선이다.
			cout << "yes" << '\n';
		}
	}
	return 0;
}
