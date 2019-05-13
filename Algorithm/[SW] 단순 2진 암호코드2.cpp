#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int rtNum(char* str) {
	if (!strcmp(str, "0001101"))
		return 0;
	else if (!strcmp(str, "0011001"))
		return 1;
	else if (!strcmp(str, "0010011"))
		return 2;
	else if (!strcmp(str, "0111101"))
		return 3;
	else if (!strcmp(str, "0100011"))
		return 4;
	else if (!strcmp(str, "0110001"))
		return 5;
	else if (!strcmp(str, "0101111"))
		return 6;
	else if (!strcmp(str, "0111011"))
		return 7;
	else if (!strcmp(str, "0110111"))
		return 8;
	else if (!strcmp(str, "0001011"))
		return 9;
	else
		return -1;
}

int main() {
	int tc, T, N, M, pwcode[8], num, sum, result;
	int y, temp;
	char pw[8][8] = { 0 };
	char str[110];

	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &M);
		num = 0, sum = 0, result = 0, temp = 0;
		for (int i = 0; i < N; i++) {
			scanf("%s", str);
			for (int j = 0; j < M; j++) {
				if (num == 8)
					break;
				y = j % 7;
				pw[num][y] = str[j + temp];

				if (y == 6 && strcmp(pw[num], "0000000")) { //7칸씩 읽는다. ㄴ
					
					pwcode[num] = rtNum(pw[num]);//암호문 생성, 배열에 따로 저장하는 부분 마음에 든다. 
					if (pwcode[num] == -1) {
						temp++;
						j = -1;
					}
					else
						num++;
				}
			}
		}
		for (int i = 0; i < 8; i++) {
			if (i % 2)
				sum += pwcode[i];
			else
				sum += pwcode[i] * 3;
			result += pwcode[i];
		}
		if (!(sum % 10))
			printf("#%d %d\n", tc, result);
		else
			printf("#%d 0\n", tc);

	}


}
