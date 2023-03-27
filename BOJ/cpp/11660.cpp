#include <iostream>
#include <vector>
using namespace std;
#define y second
#define x first

int arr[1025][1025] = { {0,},};

int solution(pair<int,int> start, pair<int, int> end){
	int result=0;
	result = arr[end.x][end.y];
	result -= arr[start.x-1][end.y];
	result -= arr[end.x][start.y-1];
	result += arr[start.x -1][start.y -1];
	return result;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,M;
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			int num;
			cin >> num;
			arr[i][j] = arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1] + num;
		}
	}
	for(int i=0; i<M; i++){
		pair<int, int> start;
		pair<int, int> end;
		cin >> start.first >> start.second >> end.first >> end.second;
		cout << solution(start, end) << '\n';
	}
	return 0;
}
