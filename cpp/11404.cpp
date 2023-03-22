#include <iostream>
#include <algorithm>
#define INF 100001
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cities, bus;
	cin >> cities >> bus;
	// cities 는 노드의 갯수, bus는 간선의 수
	int city[cities+1][cities+1];	
	fill_n(&city[0][0], (cities+1)*(cities+1), INF);
	for(int i=1; i<=cities; i++){
		city[i][i] = 0;
	}
	for(int i=0; i<bus; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		if(city[from][to] > weight){
			city[from][to] = weight;
		}
	}
	for(int k=1; k<=cities; k++){
		for(int i=1; i<=cities; i++){
			for(int j=1; j<=cities; j++){
				if(city[i][k] + city[k][j] < city[i][j]){
					city[i][j] = city[i][k] + city[k][j];
				}
			}
		}
	}
	for(int i=1; i<=cities; i++){
		for(int j=1; j<=cities; j++){
			if(city[i][j] == INF){
				city[i][j] = 0;
			}
			cout << city[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
