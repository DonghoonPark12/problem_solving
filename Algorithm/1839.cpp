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
	//int three = 0; int five = N / 5; //1) ó���� ���� 5�� ������. ���� �������� ���� ī��Ʈ �Ѵ�. 
	//N = N % 5;
	//while (five >= 0) { //3) 5�� �ٽ� ���ߴµ��� 3���� �ȳ����� �������� break
	//	if (N % 3 == 0) {
	//		three = N / 3;
	//		N = N % 3;
	//		break;
	//	}
	//	five--; //2) 3���� �� ������ �������� 5�� ���Ѵ�??? ex)6, 7
	//	N += 5;
	//}

	int N, B = 0;

	scanf("%d", &N);

	while (1) {
		if (N % 5 == 0) {
			printf("%d", N / 5 + B); //5�� ������ ���� ���� ���.
			break;
		}
		else if (N < 0) {
			printf("-1"); //
			break;
		}
		N -= 3; //3�� ���� ����, 
		B++;
	}

	//cout<< (N==0) ? five + three : -1;
	cout << B;
	return 0;

}
