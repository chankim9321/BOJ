#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

map<char, int> huffman;
class NodeType{
	public:
		int freq;
		char ch;
		NodeType* left;
		NodeType* right;
		NodeType(int freq, char ch){
			this->freq = freq;
			this->ch = ch;
			left = NULL;
			right = NULL;
		}
};
struct compare{
	bool operator()(NodeType* n1, NodeType* n2){
		return n1->freq > n2->freq;
	}
};
priority_queue<NodeType*, vector<NodeType*>, compare> pq;
void init(){
	// 빈도수를 힙에 삽입
	pq.push(new NodeType(450, 'A'));
	pq.push(new NodeType(90, 'T'));
	pq.push(new NodeType(120, 'G'));
	pq.push(new NodeType(270, 'C'));
}
NodeType* setHuffmanTree(){
	while(pq.size() >= 2){
		NodeType* n1 = pq.top(); pq.pop();
		NodeType* n2 = pq.top(); pq.pop();
		int sumFreq = n1->freq + n2->freq;
		NodeType* n3 = new NodeType(sumFreq, ' ');
		if(n1->freq < n2->freq){
			n3->left = n1;
			n3->right = n2;
		}
		else{
			n3->left = n2;
			n3->right = n1;
		}
		pq.push(n3);
	}
	return pq.top();
}
void setHuffmanMap(map<char, string>& dict, NodeType* root, string cp){
	if(!root) return;
	if(root->ch != ' '){
		dict.insert({root->ch, cp});
		cout << "문자 [" << root->ch << "] 는 [" << cp << "] 으로 압축되었습니다. \n";
	}
	cp += "0";
	setHuffmanMap(dict, root->left, cp);
	cp.pop_back();
	cp += "1";
	setHuffmanMap(dict, root->right, cp);
	cp.pop_back();
}
int main(int argc, char* argv[]){
	init();
	NodeType* root = setHuffmanTree();
	map<char, string> compress;
	setHuffmanMap(compress, root, "");
	string input = "ATGCZ";
	string output = "";
	cout << "압축하려는 문자열 = [" << input << "]\n";
	for(int i=0; i<input.length(); i++){
		string result;
		if(compress.find(input[i]) != compress.end()){
			cout << "문자 [" << input[i] << "] 가 성공적으로 압축되었습니다. (압축성공)\n";
			result = compress[input[i]];
		}
		else{
			cout << "문자 [" << input[i] << "] 는 압축 리스트에 등록되어있지 않습니다. (압축실패)\n";
			result = input[i];
		}
		output += result;
	}
	cout << "압축 결과는 다음과 같다 --> " << input << " = " << output << '\n';

	return 0;
}
