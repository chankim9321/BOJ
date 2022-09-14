#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector<int> visited(100001,0);
vector<pair<int, int> > sequence;
void print_pair(pair<int,int> &node){
	cout << node.second << endl;
}
int seq=1;
class Node{
  public:
    int vertex;
    list<Node*> link; 
    // Method
    void setVertex(int vertex){
      this->vertex=vertex;
    }
    void setLink(Node* vertex){
      link.push_back(vertex);
    }
};
void dfs(Node a[],int start){
  Node ptr=a[start];
  list<Node*>::iterator iter;
  sequence.push_back(make_pair(ptr.vertex, seq++));
  visited[start]=1; // visited present vertex
  for(iter=ptr.link.begin(); iter != ptr.link.end(); iter++){
    int next=(*iter)->vertex;
    if(!visited[next]){ 
      dfs(a,next); 
    }
  }
}
int main(){
  list<Node*>::iterator iter;
  int numOfVertex, numOfEdge, root;
  cin >> numOfVertex >> numOfEdge >> root;
  Node *graph=new Node[numOfVertex+1]; 
  for(int i=1; i<=numOfVertex; i++){
    graph[i].setVertex(i);
  }
  for(int i=1; i<=numOfEdge; i++){
    int v;
    int w;
    cin >> v >> w;
    graph[v].setLink(&graph[w]);
	graph[w].setLink(&graph[v]);
  }
  for(int i=1; i<=numOfVertex; i++){ 
    graph[i].link.sort();
  }
  dfs(graph,root);
  sort(sequence.begin(), sequence.end());
  for_each(sequence.begin(), sequence.end(), print_pair);
  for(int i=1; i<=numOfVertex; i++){ 
    if(!visited[i]){
      visited[i]=1;
	  cout << 0 << endl;
    }  
  }
  return 0;
}
