#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int n, n_his, Ans;
	char b;
	char dart[10];

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	//scanf("%s", &dart);

	/*
	두 개씩 받는다.
	그다음 두개를 받을 시 옵션이 들어오면, 두번째 것은 받지 않는다.
	그리고 앞전에 받아놓은 두개를 가지고 계산을 진행
	*/
	int test_case;
	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++) {

		for (int i = 0; i < 3; i++) {
			int opt = 0;
			int flag = 0;
			scanf("%1d", &n); //1 //*

			if (n <= 10 && n >= 0) {
				n_his = n;
			}

			if (n > 10) {
				flag = 1;
				opt = n;
			}

			if (!flag) {
				scanf("%1c", &b); //S

				if (b == 'S') {
					Ans += n;
				}
				else if (b == 'D') {
					Ans += n * n;
				}
				else { // B == 'S'
					Ans += n * n * n;
				}
				flag = 0;
			}

			if (opt) {
				if (opt == '*') {
					Ans -= n_his;
					Ans += n_his * 2;
				}
				else { // opt == #
					Ans -= n_his;
					Ans += n_his * (-1);
				}
			}
		}
	}
}


//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//
//int main() {
//	int Ans = 0;
//
//
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	int n1, n2, n3;
//	char b1, b2, b3;
//	char opt1, opt2, opt3, trash;
//
//
//
//	int test_case;
//	scanf("%d", &test_case);
//	for (int t = 0; t < test_case; t++) {
//
//		int flag1 = 0;
//		int flag2 = 0;
//
//		scanf("%d", &n1); //1
//
//		b1 = getchar(); //S
//
//		if (b1 == 'S') {
//			n1 = n1;
//		}
//		else if (b1 == 'D') {
//			n1 = n1 * n1;
//		}
//		else { // B == 'S'
//			n1 = n1 * n1 * n1;
//		}
//
//		scanf("%c", &opt1); //*
//
//		if (opt1 == '*' || opt1 == '#') {
//			if (opt1 == '*') {
//				n1 = n1 * 2;
//			}
//			else { // opt == #
//				n1 = n1 * (-1);
//			}
//		}
//		else {
//			n2 = (int)opt1 - 48;
//			flag1 = 1;
//		}
//
//		if (!flag1) {
//			scanf("%d", &n2); // 옵션이 
//		}
//
//		b2 = getchar();
//
//		if (b2 == 'S') {
//			n2 = n2;
//		}
//		else if (b2 == 'D') {
//			n2 = n2 * n2;
//		}
//		else { // B == 'S'
//			n2 = n2 * n2 * n2;
//		}
//
//		scanf("%c", &opt2); //*
//
//		if (opt2 == '*' || opt2 == '#') {
//			if (opt2 == '*') {
//				n2 = n2 * 2;
//				n1 = n1 * 2;
//			}
//			else { // opt == #
//				n2 = n2 * (-1);
//			}
//		}
//		else {
//			n3 = (int)opt2 - 48;
//			flag2 = 1;
//		}
//		if (!flag2) {
//			scanf("%d", &n3);
//		}
//		b3 = getchar();
//
//		if (b3 == 'S') {
//			n3 = n3;
//		}
//		else if (b3 == 'D') {
//			n3 = n3 * n3;
//		}
//		else { // B == 'S'
//			n3 = n3 * n3 * n3;
//		}
//
//		scanf("%c", &opt3); //*
//
//		if (opt3 == '*' || opt3 == '#') { //기호면은 계산을 해서 값을 반영하고
//			if (opt3 == '*') {
//				n3 = n3 * 2;
//				n2 = n2 * 2;
//			}
//			else { // opt == #
//				n3 = n3 * (-1);
//			}
//			printf("%d\n", n1 + n2 + n3); //그 후 프린트 뒤의 \n이 줄바꿈 문자를 먹는다. 
//
//		}
//		else { //기호가 아니고 줄바꿈 문자열이면 바로 프린트
//			printf("%d\n", n1 + n2 + n3); // 그리고 줄바꿈 진행
//		}
//
//	}
//}
