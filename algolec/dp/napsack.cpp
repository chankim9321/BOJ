#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> items;
int maxWeight = 5;
void init(){
	items.push_back({0,0}); // dummy value
	items.push_back({5, 60});
	items.push_back({3, 50});
	items.push_back({4, 70});
	items.push_back({2, 30});
}
void napsack(vector<vector<int>>& dpTable){
	for(int i=1; i<=items.size(); i++){
		for(int j=1; j<=maxWeight; j++){
			if(j-items[i].first > -1){
				dpTable[i][j] = max(dpTable[i-1][j], dpTable[i-1][j-items[i].first] + items[i].second);
			}
			else dpTable[i][j] = dpTable[i-1][j];
		}
	}
	cout << "Optimal Value = " << dpTable[items.size()-1][maxWeight] << '\n';
}
void printDpTable(vector<vector<int>> &table){
	for(int i=1; i<items.size(); i++){
		for(int j=0; j<=maxWeight; j++){
			cout << table[i][j] << " ";
		}
		cout << '\n';
	}
}
void backTracking(vector<vector<int>> &table, pair<int, int> start){
	int y = start.first;
	int x = start.second;
	if( x == 0 || y == 0) return;
	if(table[y][x] == table[y-1][x]){
		backTracking(table, {y-1,x});
	}
	else{
		cout << "used item " << y << " (weight = " << items[y].first << ", value = " << items[y].second << " )" << '\n';
		backTracking(table, {y-1,x-items[y].first});
	}
}
int main(int argc, char* argv[]){
	init();
	vector<vector<int>> dpTable(items.size()+1, vector<int>(maxWeight+1,0));
	napsack(dpTable);
	printDpTable(dpTable);
	backTracking(dpTable, {items.size()-1, maxWeight});
	return 0;
}
