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
				strncpy(Store, Str + i, i); //Store에 Str+i(부터)를 i만큼 복사. 끝에 '\0'문자는 자동으로 붙지 않는다. 
				if (strncmp(Store, Str, i) == NULL) //동일하면 NULL('\0'), Store가 더 크면 양수, Str이 더 크면 음수 반환
				{ 
					result = i;
					break;
				}
			}
		}
		printf("#%d %d\n", testCase, result);
	}
}
