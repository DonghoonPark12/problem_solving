#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
���� 1 : �ڼ��� �ڼ�ü�� �Ÿ��� ������� ���� ���� �־�����.
���� 2 : �ڼ�ü�� ���ֺ��� �ڼ�ü�� ������ ������� �������¿� ������.
���� 3 : �¿쿡 ��ġ�� �ڼ�ü������ ���� �ۿ����� �ʴ´�.
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
			for (int j = 0; j < len; ++j) { //���η� ����. 
				if (arr[j][i] == 1) //N���� ������
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