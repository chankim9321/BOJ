#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	int cities;
	cin >> cities;
	vector<int> roads(cities-1);
	vector<int> city(cities);
	int i=0;
	do {
		cin >> roads[i];
		i++;
	}while(getc(stdin) == ' '); 
	i=0; 
	do{ 
		cin >> city[i]; 
		i++;
	}while(getc(stdin) == ' ');
	int cheeper=city[0];
	long long int fee=0;
	long long int distance=roads[0];
	for(int i=1; i<city.size()-1; i++){
		if(city[i] < cheeper){	
			fee+=cheeper*distance;
			cheeper=city[i];
			distance=0;
			distance+=roads[i];
		}
		else {
			distance+=roads[i];
		}
	
	}
	fee+=cheeper*distance;
	cout << fee;

}
