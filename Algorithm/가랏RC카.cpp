#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int vel[30];

int main() {

	freopen("input.txt","r", stdin);
	setbuf(stdout, NULL);
	int test_case;
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++) {
		int n;
		scanf("%d", &n);
		int time;

		int backup = 0;
		int range = 0;
		int acc = 0;

		for (int i = 0; i < n; i++) {
			scanf(" %d", &time);

			if (time == 1) {
				scanf(" %d", &acc);
				vel[i] = backup + acc;
				backup += acc;
			}
			else if (time == 0) {
				vel[i] = backup;
			}
			else if (time == 2) {
				scanf(" %d", &acc);
				if (backup == 0) continue;//현재 속도가 0이라면 (감속 값을 받고) 스킵
				vel[i] = backup - acc;
				backup -= acc;
			}
		}

		for (int i = 0; i < n; i++) {
			range += vel[i];
			vel[i] = 0;
		}

		printf("#%d %d\n", t + 1, range);
	}

}
