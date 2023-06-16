#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> jobs = {5,2,4,3,4,7,9,2,4,1};
vector<int> machine = {0,0,0,0};
void approximationJobScheduling(){
	cout << " -------------------- ApproximationJobScheduling -----------------------" << '\n';
	for(int i=0; i<jobs.size(); i++){
		int time = jobs[i];
		int minIdx = 0;
		for(int j=0; j<machine.size(); j++){
			if(machine[minIdx] > machine[j]){
				minIdx = j;
			}
		}
		machine[minIdx] += time;
		cout << "machine " << minIdx+1 << " task assigned! ( task: " << time << " )" << '\n'; 
	}
	int maxTime = 0;
	for(int i=0; i<machine.size(); i++){
		maxTime = max(machine[i], maxTime);	
		cout << "number " << i+1 << " machine: " << machine[i] << '\n';
	}
	cout << "latest task time: " << maxTime << '\n';
	cout << " ---------------------------------------------------------------------- " << '\n';
}
bool compare(int &a, int &b){
	return a > b;
}
void LPTscheduling(){
	cout << " ------------------------ LPT JobScheduling ---------------------------" << '\n';
	sort(jobs.begin(), jobs.end(), compare);
	machine = {0,0,0,0};
	for(int i=0; i<jobs.size(); i++){
		int time = jobs[i];
		int minIdx = 0;
		for(int j=0; j<machine.size(); j++){
			if(machine[minIdx] > machine[j]){
				minIdx = j;
			}
		}
		machine[minIdx] += time;
		cout << "machine " << minIdx+1 << " task assigned! ( task: " << time << " )" << '\n'; 
	}
	int maxTime = 0;
	for(int i=0; i<machine.size(); i++){
		maxTime = max(machine[i], maxTime);	
		cout << "number " << i+1 << " machine: " << machine[i] << '\n';
	}
	cout << "latest task time: " << maxTime << '\n';
	cout << " ---------------------------------------------------------------------- " << '\n';
}
int main(){
	approximationJobScheduling();
	LPTscheduling();
	return 0;
}
