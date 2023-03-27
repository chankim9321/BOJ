#include <iostream>
#include <vector>
using namespace std;
class Node{
	public:
		vector<Node*> links;
};
int main(int argc, char* argv[]){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int result;
	int nodes;
	cin >> nodes;
	Node* network = new Node[nodes+1];
	for(int i=1; i<nodes; i++){

		cin >> from >> to;
		network[from].links.push_back(&network[to]);
		//network[to].links.push_back(&network[from]);
	}
	int DP[level+1];
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = network[1].links.size();
	for(int i=4; i<=level; i++){
		DP[i] = child[i-2] + DP[i-2];
	}
	int max = 0;
	cout << DP[level] << '\n';
	return 0;
}
