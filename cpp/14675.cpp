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
		Tree[to].link.push_back(&Tree[from]);
	}
	Tree[vertex].id = vertex;
	// init end
	cin >> query;
	for(int i=0; i<query; i++){
		int q, removed;
		cin >> q >> removed;
		if(q == 1){ // 단절점인지에 대한 질의, 노드의 링크가 하나밖에 없으면 단절점이 아니다.
			if(Tree[removed].link.size() == 1) cout << "no" << '\n';
			else cout << "yes" << '\n';
		}
		else{ // 단절선인지에 대한 질의
			// 정점이 무조건 2개 이상이므로 어느 간선을 자르던간에 단절선이다.
			cout << "yes" << '\n';
		}
	}
	return 0;
}
