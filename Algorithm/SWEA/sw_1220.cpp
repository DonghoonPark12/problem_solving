#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
전제 1 : 자석과 자성체의 거리에 상관없이 일정 힘이 주어진다.
전제 2 : 자성체와 마주보는 자성체는 갯수와 상관없이 교착상태에 빠진다.
전제 3 : 좌우에 위치한 자성체끼리는 힘이 작용하지 않는다.
*/
//int N;
//int a[100];
//int main() {
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	for (int test = 1; test <= 10; test++) {
//		int flag[100] = { 0 };
//		int ans = 0;
//		scanf("%d", &N);
//		for (int i = 0; i < 100; i++) {
//			for (int j = 0; j < 100; j++) {
//				scanf("%d", &a[j]);
//				if (a[j] == 1) flag[j] = 2;
//				else if (a[j] == 2 && flag[j] == 2) {
//					flag[j] = 1; ans++;
//				}
//			}
//		}
//		printf("#%d %d\n", test, ans);
//	}
//	return 0;
//}

int main() {
	int len, arr[100][100], res;
	bool chk;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	for (int t = 1; t <= 10; ++t) {
		res = 0;
		scanf("%d", &len);
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) scanf("%d", &arr[i][j]);
		}
		for (int i = 0; i < len; ++i) {
			chk = false;
			for (int j = 0; j < len; ++j) { //세로로 본다. 
				if (arr[j][i] == 1) //N극이 있으면
					chk = true;
				else if (arr[j][i] == 2 && chk==1 ) {
					res++;
					chk = false;
				}
			}
		}
		printf("#%d %d\n", t, res);
	}
}