#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Node{
public:
	int value;
	list<Node*> link;
	Node(){
		value=0;
	}
};

list <Node*> li;
void bfs(Node tree[], int root){
	vector<int> visited(100001,0);
	queue<Node*> buf;
	visited[1]=1;
	list<Node*>::iterator iter;
	for(iter=tree[root].link.begin(); iter !=tree[root].link.end(); iter++){
		buf.push((*iter));
	}
	while(!buf.empty()){
		Node* ptr=buf.front();
		li.push_back(ptr);
		visited[ptr->value]=1;
		buf.pop();
		for(iter=ptr->link.begin(); iter!=ptr->link.end(); iter++){
			if(!visited[(*iter)->value]) buf.push((*iter));
		}
	}
}
int main(int argc, char* argv[]){
	int num;
	cin >> num;
	Node* tree=new Node[num+1];
	for(int i=1; i<=num; i++){
		tree[i].value=i;
	}
	for(int i=1; i<num; i++){
		int v;
		int w;
		cin >> v >> w;
		tree[v].link.push_back(&tree[w]);
		tree[w].link.push_back(&tree[v]);
	}
	bfs(tree,1);
	li.sort();
	list<Node*>::iterator iter;
	for(iter=li.begin(); iter != li.end(); iter++){
		printf("%d\n",(*iter)->link.front()->value);
	}
	return 0;
}
