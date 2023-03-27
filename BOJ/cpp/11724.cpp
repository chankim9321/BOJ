#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
	public:
		int id;
		vector<Node*> link;
		bool is_visited;
};

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int vert, edge;
	cin >> vert >> edge;
	Node* arr = new Node[vert+1];

	for(int i=1; i<=vert; i++){ // init
		arr[i].id = i;
		arr[i].is_visited = false;
	}
	for(int i=0; i<edge; i++){  // init edge info
		int from, to;
		cin >> from >> to;
		arr[from].link.push_back(&arr[to]);
		arr[to].link.push_back(&arr[from]);
	}
	int connected_element=0;
	for(int i=1; i<=vert; i++){
		if(!arr[i].is_visited){
			connected_element++;
			queue<Node*> q;
			q.push(&arr[i]);
			arr[i].is_visited = true;
			while(!q.empty()){
				Node* vertex = q.front();
				q.pop();
				for(int i=0; i<vertex->link.size(); i++){
					if(!vertex->link[i]->is_visited){
						vertex->link[i]->is_visited = true;
						q.push(vertex->link[i]);
					}
				}
			}
		}
	}
	cout << connected_element << '\n';
	return 0;
}
