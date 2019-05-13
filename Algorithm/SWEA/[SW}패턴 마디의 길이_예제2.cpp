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

		for (int i = 1; i < 10; i++) { //애초에 패턴은 10자 이내이므로 처음부터 10자만 검사했다. 
			if (str[i] == str[head]) {
				head++;
			}
			else {
				cnt = i;
				head = 0; //head는 다시 원래 자리로
			}
		}
		printf("#%d %d\n", test, cnt + 1);
	}
	return 0;
}
