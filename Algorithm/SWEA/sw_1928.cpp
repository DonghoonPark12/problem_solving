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

		// 6��Ʈ�� �о� Encoding 
		int sum = 0;
		int e = 5;
		int n = 0;

		for (int j = 0; j < 23; j += 11) {
			for (int i = 5 + j; i >= j; i--) {
				sum += *buf & 1>>5;
			}
			// ���ڵ� �� ���� -> ���� ���ڵ� 
			// n�� �����µ��� �ٷιٷ� ������� 
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
1. ���ڸ� ���� �о� �鿩�� �ڴ�. 4����. �̶� ���� ���� �߰ߵǵ� ��� ����. 
2. ���ڸ� ������ ���ڷ� �ٲ۴�. 
3. �ٲ� ���ڸ� 24bit�� ��ġ ��Ų��.
4. 24bit���� 1byte(8 bit)�� �о� ���δ�.
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