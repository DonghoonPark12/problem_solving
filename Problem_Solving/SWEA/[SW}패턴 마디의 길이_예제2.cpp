#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (int test = 1; test <= T; test++) {
		string str;
		cin >> str;
		int head = 0;
		int cnt = 1;

		for (int i = 1; i < 10; i++) { //���ʿ� ������ 10�� �̳��̹Ƿ� ó������ 10�ڸ� �˻��ߴ�. 
			if (str[i] == str[head]) {
				head++;
			}
			else {
				cnt = i;
				head = 0; //head�� �ٽ� ���� �ڸ���
			}
		}
		printf("#%d %d\n", test, cnt + 1);
	}
	return 0;
}
