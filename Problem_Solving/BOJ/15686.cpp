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
		}//total_dist �� ������ ġŲ�Ÿ�.

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

	//int dist;     //����ؾ��ϴ� �Ÿ� ��.
	//int min_dist; //�����ϱ� ���� �ּҰŸ�
	//int min_j;    //�����ϱ� ���� �ּҰŸ��� ġŲ�� ��ġ
	//int i, j;
	//for (i = 0; i < house.size(); i++) {
	//	min_dist = 1000;
	//	for (j = 0; j < shop.size(); j++) {
	//		dist = abs(house[i].x - shop[j].x) + abs(house[i].y - shop[j].y);
	//		if (dist < min_dist) {
	//			min_dist = dist; // ��������(i) �ּҰ� �Ǵ� �Ÿ��� ã��
	//			min_j = j;       // �� ������ ����� �д�.
	//		}
	//	}
	//	shop[min_j].live = 1;    // ������ �ȳ����� ���� ��Ų��.
	//}

	//

	/*
	int ans = 0;
	for (int i = 0; i < pick.size(); i++) { //����� �͵�
		min_dist = INT_MAX;
		for(int j=0;j<house.size();j++){ //��� �������� �Ÿ��� ���
			dist = abs(pick[i].x - house[j].x) + abs(pick[i].y - house[j].y);
			if(dist < min_dist)
				min_dist = dist;
			//���� ª�� ġŲ �Ÿ� ��� 
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