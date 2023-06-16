#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> items = {7,5,6,4,2,3,7,5};
	vector<int> bin = {0}; 
	int volume = 10;

	for(int i=0; i<items.size(); i++){
		int item = items[i];
		int minCapacity = volume+1;
		int minIdx = -1;
		for(int j=0; j<bin.size(); j++){
			if(bin[j] + item <= 10){
				if(volume - bin[j] < minCapacity){
					minCapacity = volume - bin[j];
					minIdx = j;
				}
			}
		}
		if(minIdx == -1){ // if there is no capacity for item 
			bin.push_back(0); // add new bin
			bin[bin.size()-1] += item;
		}
		else{ // best fit
			bin[minIdx] += item;
		}
		for(int i=0; i<bin.size(); i++){
			cout << bin[i] << ", ";
		}
		cout << '\n';
	}
	cout << "Result: " << '\n';
	for(int i=0; i<bin.size(); i++){
		cout << bin[i] << ", ";
	}
	cout << '\n';
	cout << items.size() << '\n';
	
}
