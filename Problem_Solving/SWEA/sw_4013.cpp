#define	_CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> arr(4, vector<int>(8));
void rotation(vector<int> &m, int dir) {
	// https://swexpertacademy.com/main/learn/course/lectureVideoPlayer.do
	if (dir == 1) { //시계 방향
		int tmp = m.back();
		m.pop_back();
		m.insert(m.begin(), tmp);
	}
	else if (dir == -1) {
		int tmp = m.front();
		m.erase(m.begin());
		m.push_back(tmp);
	}
	else {}
}
void rotate_strategy(int which, int dir) {
	//int st[3];
	vector<int> st(3, 0);
	for (int i = 0; i < 3; i++) {
		if (arr[i][2] != arr[i + 1][6])
			st[i] = 1;
	}

	rotation(arr[which], dir);
	switch (which) {
	case 0:
		//if (arr[0][2] != arr[1][6]) {
		//	rotation(arr[1], dir*(-1));
		//	if (arr[1][2] != arr[2][6]) {
		//		rotation(arr[2], dir);
		//		if (arr[2][2] != arr[3][6])
		//			rotation(arr[3], dir*(-1));
		//	}
		//}
		if (st[0]) {
			rotation(arr[1], dir*(-1));
			if (st[1]) {
				rotation(arr[2], dir);
				if (st[2]) rotation(arr[3], dir*(-1));
			}
		}
		break;
	case 1:
		//if (arr[0][2] != arr[1][6]) 
		//	rotation(arr[0], dir * (-1));
		//if (arr[1][2] != arr[2][6]) {
		//	rotation(arr[2], dir * (-1));
		//	if (arr[2][2] != arr[3][6])
		//		rotation(arr[3], dir);
		//}
		if (st[0]) rotation(arr[0], dir*(-1));
		if (st[1]) {
			rotation(arr[2], dir*(-1));
			if (st[2]) rotation(arr[3], dir);
		}
		break;
	case 2:
		//if (arr[1][2] != arr[2][6])
		//	rotation(arr[1], dir * (-1));
		//if (arr[2][2] != arr[3][6]) {
		//	rotation(arr[3], dir * (-1));
		//	if (arr[0][2] != arr[1][6])
		//		rotation(arr[0], dir);
		//}
		if (st[1]) {
			rotation(arr[1], dir*(-1));
			if (st[0]) rotation(arr[0], dir);
		}
		if (st[2])  rotation(arr[3], dir*(-1));
		break;
	case 3:
		//if (arr[2][2] != arr[3][6]) {
		//	rotation(arr[2], dir*(-1));
		//	if (arr[1][2] != arr[2][6]) {
		//		rotation(arr[1], dir);
		//		if (arr[0][2] != arr[1][6])
		//			rotation(arr[0], dir*(-1));
		//	}
		//}
		if (st[2]) {
			rotation(arr[2], dir*(-1));
			if (st[1]) {
				rotation(arr[1], dir);
				if (st[0]) rotation(arr[0], dir*(-1));
			}
		}
		break;
	}
}
int fac_two(int n) {
	int ans = 1;
	if (n == 0)
		return 1;
	else {
		for (int i = 0; i < n; i++)
			ans *= 2;
	}
	return ans;
}
int get_score() {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1)
			ret += fac_two(i);
	}
	return ret;
}
int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		int rot_num; cin >> rot_num;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr[i][j];
			}
		}
		
		while (rot_num--) {
			int which, dir;
			cin >> which >> dir;
			rotate_strategy(which-1, dir);//1번 자석이 0번 위치
		}
		Answer = get_score();

		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}