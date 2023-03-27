#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int width, height;
	cin >> width >> height;
	long long toUp[height+1];
	long long toDown[height+1];
	fill_n(&toUp[0], height+1, 0);
	fill_n(&toDown[0], height+1, 0);
	for(int i=0; i<width; i++){
		int n;
		cin >> n;
		if(i % 2 == 0){
			toUp[n]++;
		}
		else{
			toDown[height - n + 1]++;
		}
	}
	for(int i=1; i<=height; i++){
		toUp[height-i] += toUp[height-i+1]; // 자기보다 큰 석순의 갯수만큼 벽이 증가한다.
		toDown[i] += toDown[i-1]; // 자기보다 작은 종유석이 존재한다면 그 갯수만큼 벽이 존재한다.
	}
	long long res= 10e15;
	int cnt=0;
	for(int i=1; i<=height; i++){
		if(toUp[i] + toDown[i] < res){
			res = toUp[i] + toDown[i];
			cnt = 1;
		}
		else if(toUp[i] + toDown[i] == res){
			cnt++;
		}
	}
	cout << res << " " << cnt << '\n';
	return 0;
}
