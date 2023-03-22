#include <stdio.h>
#include <vector>
using namespace std;

void deleteBuffer(){
	while(getchar() != '\n');
}
int h,w;
int calculateDist(vector<vector<char>> &map, int posY, int posX){
	int dist = 0;
	for(int i = posX; i>=0; i--){
		if(map[posY][i] == 'c') break;
		else dist++;
	}
	if(dist-1 == posX) return -1;
	return dist;
}
int main(int argc, char* argv[]){
	scanf("%d %d",&h, &w);
	deleteBuffer();
	vector<vector<char>> map(h, vector<char> (w,' '));
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			scanf("%1c", &map[i][j]);
		}
		deleteBuffer();
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			printf("%d ", calculateDist(map, i, j));
		}
		printf("\n");
	}

	return 0;
}
