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
		yes = 0;//��ġ���� �˻��ϱ� ���� ���Կ��� Ȯ�� ���� �ʱ�ȭ
		cnt = 0;
		for (int i = 0; i <= strlen(save)- len + 1; i++) { // 1000 - len(��ū����)�� �Ǿ� �´�. 
			/*------�����ϴ��� �˻��ϴ� �κ�------*/
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