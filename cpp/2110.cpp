#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

class Node{
	public:
		int number; // 노드 고유 ID
		int dist; // 노드 X좌표
		bool is_installed; // 라우터 설치 여부
};
// binary search 이용 
// 산정된 중간값에서 가장 가까운 노드의 좌표를 반환하는 함수.
// 매개변수는 노드집합을 가지는 벡터와, 라우터 설치에 가장 적절한 X좌표를 받고,  최적 X좌표를 구할때 사용한 노드의 인덱스를 받는다.
int getOpt(int a, int b, int c){
	int min=a;
	if(min > b){
		min = b;
		if(min > c){
			min = c;
		}
	}
	return min;
}
int getClosest(vector<Node*> v, int opt_mid, int start_idx, int end_idx){ 
	//cout << "executing getClosest func" << '\n';
	int mid_idx;
	int res;
	int answer;	
	while(start_idx <= end_idx){
		mid_idx = (end_idx + start_idx)/2; // 중간 인덱스
	//	cout << "mid_idx = " << mid_idx << '\n';
		int mid_idx_dist = v[mid_idx]->dist;	 // 중간 인덱스의 좌표 값
		//cout << "mid = " << mid << " , " << "mid_idx_dist = " << mide_idx_dist << '\n'; 
		res = opt_mid - mid_idx_dist; // 최적 중간값과 실제 중간 인덱스 값의 차이
		//cout << "res = " << res << '\n';
		if(start_idx == end_idx){
			int a = abs(opt_mid - v[mid_idx-1]->dist);
			int b = abs(opt_mid - v[mid_idx+1]->dist);
			int c = abs(opt_mid - v[mid_idx]->dist);
			int opt_dist = getOpt(a,b,c);
			if(opt_dist == a) return mid_idx-1;
			else if(opt_dist == b) return mid_idx+1;
			else return mid_idx;
		}
		else if(res > 0){ 
			start_idx = mid_idx+1;
			answer = mid_idx; // 일단 조건을 만족한 값부터 저장
		}
		else if(res < 0){ 
			end_idx = mid_idx;
		}
		else{
			return mid_idx;
		}
	}
	//cout << "finishing getClosest func" << '\n';
	//cout << "returning " << answer << '\n';
	return answer;
}
bool asce(Node* a, Node* b){
	return a->dist < b->dist;
}
int solution(int router, vector<Node*> v){
	int answer;
	int mid;
	priority_queue<int> router_dist; // 우선순위 큐 선언, 라우터 간의 거리를 저장한다.
	vector<Node*> router_installed; // 라우터가 설치된 노드를 저장하는 벡터

	Node* start = (v.front()); // minimum
	Node* end = (v.back()); // maximum

	start->is_installed = true;
	end->is_installed = true;

	router_installed.push_back(start);
	router_installed.push_back(end);
	router -=2; // 양 끝에 라우터를 설치했으므로 -2개

	int diff_dist = end->dist - start->dist; // 시작점 노드와 끝점 노드 사이의 거리. 이는 두 라우터사이의 최대 거리이다.
	router_dist.push(diff_dist); // 힙에 삽입

	while(router){ // 라우터가 다 없어질 떄 까지
		mid = (start->dist + end->dist)/2; // 산정된 최적의 중간값
		int closest_idx = getClosest(v, mid, start->number, end->number);
		//cout << closest_idx << '\n';
		Node *new_ins = v[closest_idx]; // 벡터와 미드값 삽입, mid값과 가장 가까운 노드를 반환한다.
		new_ins->is_installed = true; // 라우터 설치	
	//	cout << "new installed node : " << new_ins->dist << '\n';
		router--; // 라우터 갯수 감소
		router_installed.push_back(new_ins); // 라우터가 설치된 노드를 저장하는 벡터에 삽입
		sort(router_installed.begin(), router_installed.end(), asce);
		// 라우터가 설치된 노드가 증가할 수록 라우터들간의 거리 정보는 한개씩 증가한다.
		int max_dist= -1;
		for(int i=0; i<router_installed.size()-1; i++){
			Node* second = router_installed[i+1];
			Node* first = router_installed[i];
			int dist = second->dist - first->dist;
	//		cout << "dist : " << dist << '\n';
			if(max_dist < dist){
				max_dist = dist;
				// start, end 업데이트
				start = first;
				end = second;
			}
			router_dist.push(dist); // 거리값이므로 절댓값을 삽입
		}
	}	
//	cout << "heap clearing .. " << "size = " << router_dist.size() << '\n';
	int size = router_dist.size();	
	for(int i=0; i<size; i++){
		answer = router_dist.top();
		router_dist.pop();
	}
//	cout << "heap clearing success! " << '\n';
	return answer;
}
int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int node;
	int router;
	cin >> node >> router;
	vector<Node*> v; // 동적으로 생성한 노드를 저장하는 벡터

	for(int i=0; i<node; i++){ // init
		Node* element = new Node;
		cin >> element->dist;
		element->number = i;
		element->is_installed = false;
		v.push_back(element);
	}
	//sort(v.begin(), v.end()); // 오름차순으로 정렬
	cout << solution(router, v) << '\n';
	return 0;
}
