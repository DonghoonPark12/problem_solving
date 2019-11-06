#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char str[100001];
/*
char buf[3];
string str;

int main() {
	int test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d ", &test_case);
	//char a, b, c;
	for (int t = 0; t < test_case; t++) {
		printf("#%d ", t + 1);

		//getline(cin, str);
		scanf("%c%c%c", &buf[0], &buf[1], &buf[2]); //TGI mZS Bpd HNI

		// 6비트를 읽어 Encoding 
		int sum = 0;
		int e = 5;
		int n = 0;

		for (int j = 0; j < 23; j += 11) {
			for (int i = 5 + j; i >= j; i--) {
				sum += *buf & 1>>5;
			}
			// 인코딩 후 숫자 -> 문자 인코딩 
			// n이 나오는데로 바로바로 출력하자 
			if (n >= 0 && n <= 25) {
				printf("%c", n + 65);
			}
			else if (n >= 26 && n <= 51) {
				printf("%c", n + 71);
			}
			else if (n >= 52 && n <= 61) {
				printf("%c", n - 4);
			}
			else if (n == 62) {
				printf("%c", n - 19);
			}
			else {
				printf("%c", n - 16);
			}
		}
	}
	return 0;
}
*/

/*
1. 문자를 먼저 읽어 들여야 겠다. 4개씩. 이때 뭐가 먼저 발견되든 상관 없다. 
2. 문자를 가지고 숫자로 바꾼다. 
3. 바꾼 숫자를 24bit로 배치 시킨다.
4. 24bit에서 1byte(8 bit)씩 읽어 들인다.
*/

int main() {
	int test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d ", &test_case);
	//char a, b, c;
	for (int t = 0; t < test_case; t++) {
		scanf("%s", str);
		int len = strlen(str);
		printf("#%d ", t + 1);
		for (int i = 0; i < len; i += 4) {
			int bit = 0;
			for (int j = 0; j < 64; j++) {
				if (str[i] == table[j]) { bit |= j << 18; }
				if (str[i + 1] == table[j]) { bit |= j << 12; }
				if (str[i + 2] == table[j]) { bit |= j << 6; }
				if (str[i + 3] == table[j]) { bit |= j; }
			}
			printf("%c%c%c", (bit & (255 << 16)) >> 16, (bit & (255 << 8)) >> 8, bit & 255);
		}
		printf("\n");
	}
	return 0;
}