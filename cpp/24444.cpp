#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
class Node{
	public:
		int number;
		vector<Node*> link;
		bool isVisited;
		int seq;
};
void bfs(int start, Node ptr[], int size){
	queue<Node*> q;
	q.push(&ptr[start]);
	int seq=1;
	while(!q.empty()){
		Node* vert = q.front();
		q.pop();
		if(!vert->isVisited){
			vert->seq = seq++;
			vert->isVisited = true;
		}
		for(int i=0; i<vert->link.size(); i++){
			q.push(vert->link[i]);
		}
	}
	for(int i=1; i<=size; i++){
		cout << ptr[i].seq << "\n";
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int vert, edge, start;
	cin >> vert >> edge >> start;
	Node *ptr = new Node[vert+1];
	for(int i=1; i<=vert; i++){ // init
		ptr[i].number = i; 
		ptr[i].isVisited = false;
		ptr[i].seq = 0;
	}

	for(int i=1; i<=vert; i++){
		int from;
		int to;
		cin >> from >> to;
		ptr[from].link.push_back(&ptr[to]); // 다른 노드의 주소를 벡터에 삽입
	}
	for(int i=1; i<=vert; i++){
		sort(ptr[i].link.begin(), ptr[i].link.end());
	}
	bfs(start, ptr, vert);
	delete[] ptr;
	return 0;
}
