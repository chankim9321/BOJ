#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int result = 0;
class Node{
	public:
		int id;
		int parentId;
		Node* rlink;
		Node* llink;
};
Node* deleteNode(Node* current){
	if(current == nullptr) return nullptr;
	queue<Node*> q;
	q.push(current);
	Node* front = nullptr;
	while(!q.empty()){
		front = q.front();
		q.pop();
		if(front->llink){
			q.push(front->llink);
		}
		if(front->rlink){
			q.push(front->rlink);
		}
		//delete front;
	}
	current = nullptr;
	return current;
}
void updateLeafNodeNumber(Node* current){
	if(current->llink == nullptr && current->rlink == nullptr) result++;
	if(current->llink) updateLeafNodeNumber(current->llink);
	if(current->rlink) updateLeafNodeNumber(current->rlink);
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	Node* tree = new Node[n];
	for(int i=0; i<n; i++){
		tree[i].id = i;
		tree[i].rlink = nullptr;
		tree[i].llink = nullptr;
		tree[i].parentId = -1;
	}
	for(int i=0; i<n; i++){
		int parent;
		cin >> parent;
		if(parent == -1) continue;
		else{
			tree[i].parentId = parent;
			// 우선순위는 llink부터 시작
			if(tree[parent].llink == nullptr){
				tree[parent].llink = &tree[i];
			}
			else if(tree[parent].llink != nullptr && tree[parent].rlink == nullptr){
				tree[parent].rlink = &tree[i];
			}
			else{
				cout << "initializing failed! " << '\n';
			}
		}
	}
	int beDeleted;
	cin >> beDeleted;
	int pid = tree[beDeleted].parentId; // 지워야 할 노드의 부모노드 id
	if(pid == -1){ // 만약 pid 가 -1이면 루트노드를 지워야 하므로 결과는 0일수 밖에 없다.
		cout << 0 << '\n';
		return 0;
	}
	// 부모노드 입장에선 두 자식 노드중 어느 자식노드가 지워져야되는지 알아야하므로
	else{
		if(tree[pid].llink->id == tree[beDeleted].id){
			tree[pid].llink = deleteNode(&tree[beDeleted]);
		}
		else{
			tree[pid].rlink = deleteNode(&tree[beDeleted]);
		}
		updateLeafNodeNumber(&tree[0]);
		cout << result << '\n';
	}
}
