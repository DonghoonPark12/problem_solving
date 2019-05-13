#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {
	int T;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {

		char Str[31] = "";
		scanf("%s", Str);

		int len = strlen(Str);

		char Store[31] = "";

		int result = 0;

		for (int i = 1; i <= len; i++) 
		{
			if (Str[0] == Str[i]) 
			{
				strncpy(Store, Str + i, i); //Store�� Str+i(����)�� i��ŭ ����. ���� '\0'���ڴ� �ڵ����� ���� �ʴ´�. 
				if (strncmp(Store, Str, i) == NULL) //�����ϸ� NULL('\0'), Store�� �� ũ�� ���, Str�� �� ũ�� ���� ��ȯ
				{ 
					result = i;
					break;
				}
			}
		}
		printf("#%d %d\n", testCase, result);
	}
}
