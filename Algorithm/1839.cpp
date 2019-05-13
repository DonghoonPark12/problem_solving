#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int Answer = 0;
	//freopen("input.txt", "r", stdin);
	int bong = 0;
	int tmp, tmp2;
	cin >> N;
	//int three = 0; int five = N / 5; //1) 처음에 먼저 5로 나눈다. 몫을 봉지수로 먼저 카운트 한다. 
	//N = N % 5;
	//while (five >= 0) { //3) 5를 다시 더했는데도 3으로 안나누어 떨어지면 break
	//	if (N % 3 == 0) {
	//		three = N / 3;
	//		N = N % 3;
	//		break;
	//	}
	//	five--; //2) 3으로 안 나누어 떨어지면 5를 더한다??? ex)6, 7
	//	N += 5;
	//}

	int N, B = 0;

	scanf("%d", &N);

	while (1) {
		if (N % 5 == 0) {
			printf("%d", N / 5 + B); //5로 나누어 질때 값을 출력.
			break;
		}
		else if (N < 0) {
			printf("-1"); //
			break;
		}
		N -= 3; //3을 먼저 빼고, 
		B++;
	}

	//cout<< (N==0) ? five + three : -1;
	cout << B;
	return 0;

}
