#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char save[1000];
char search[10];
int main() {
	freopen("input.txt", "r", stdin);
	//getline(save, stdin);
	int cnt;
	int yes;
	int n;
	for (int t = 0; t < 10; t++) {
		scanf("%d", &n);
		scanf("%s", search);
		scanf("%s", save);
		int len = strlen(search);
		yes = 0;//겹치는지 검사하기 전에 포함여부 확인 변수 초기화
		cnt = 0;
		for (int i = 0; i <= strlen(save)- len + 1; i++) { // 1000 - len(토큰길이)가 되야 맞다. 
			/*------포함하는지 검사하는 부분------*/
			if (save[i] == search[0]) {
				for (int j = 1; j < len; j++) {
					if (save[i + j] == search[j])
						cnt++;
				}
				if (cnt == len - 1) {
					yes++;
					cnt = 0;
				}
				cnt = 0;
			}
			/*------------------------------------*/
		}
		printf("#%d %d\n", t + 1, yes);
	}
	return 0;
}