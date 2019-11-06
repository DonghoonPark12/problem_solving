#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _info {
	int live;
	int y, x;
}info;

int n, m, ret;
int map[50][50];
vector<info> house, shop, pick;


void dfs(int pos) {

	if (pick.size() == m) {
		int total_dist = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 1000;
			for (int j = 0; j < pick.size(); j++) {
				min_dist = min(min_dist,
							   abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
			}
			total_dist += min_dist;
		}//total_dist 는 도시의 치킨거리.

		if (ret > total_dist)
			ret = total_dist;
		return;
	}

	for (int i = pos; i < shop.size(); i++) { 
		//if (shop[i].live == 1) {
			pick.push_back(shop[i]);
			dfs(i + 1);
			pick.pop_back();
		//}
	}
}


int main() {
	cin >> n >> m;
	//info target;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				//target.y = i, target.x = j;
				//house.push_back(target);
				house.push_back({ 0, i, j });
			}
			if (map[i][j] == 2) {
				//target.y = i, target.x = j;
				//shop.push_back(target);
				shop.push_back({ 0, i, j });
			}
		}
	}

	//int dist;     //계산해야하는 거리 값.
	//int min_dist; //갱신하기 위한 최소거리
	//int min_j;    //갱신하기 위한 최소거리의 치킨집 위치
	//int i, j;
	//for (i = 0; i < house.size(); i++) {
	//	min_dist = 1000;
	//	for (j = 0; j < shop.size(); j++) {
	//		dist = abs(house[i].x - shop[j].x) + abs(house[i].y - shop[j].y);
	//		if (dist < min_dist) {
	//			min_dist = dist; // 한집에서(i) 최소가 되는 거리를 찾고
	//			min_j = j;       // 그 지점을 기억해 둔다.
	//		}
	//	}
	//	shop[min_j].live = 1;    // 매출이 안나오니 제외 시킨다.
	//}

	//

	/*
	int ans = 0;
	for (int i = 0; i < pick.size(); i++) { //골라진 것들
		min_dist = INT_MAX;
		for(int j=0;j<house.size();j++){ //모든 집까지의 거리를 계산
			dist = abs(pick[i].x - house[j].x) + abs(pick[i].y - house[j].y);
			if(dist < min_dist)
				min_dist = dist;
			//가장 짧은 치킨 거리 계산 
		}
		ans += min_dist;
	}
	cout << ans;
	*/
	
	ret = 0x7fffffff;
	dfs(0);
	cout << ret;

	return 0;
}