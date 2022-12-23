#include <iostream>
#include <vector>
using namespace std;

int n, s;
int result = 0;
bool visited[20];
void sol(int arr[], int depth, int value){
	if(value == s && depth != 0){
		result++;
	}
	for(int i=depth; i<n; i++){
		if(visited[i]) continue;
		visited[i] = true;
		sol(arr, i, value + arr[i]);
		visited[i] = false;
	}
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sol(arr, 0, 0);
	cout << result << '\n';
}
