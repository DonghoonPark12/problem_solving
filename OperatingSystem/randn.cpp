#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
/*
srand�� ȣ���� �� ���޹��� ���ڸ� ������� ������ �ʱ�ȭ
rand�� srand�� ���� ������ ���� �������� ������ ����.
time �Լ��� ���ڰ����� NULL�� �ѱ�� 1970�� 1�� 1�� 0��(UTC Ÿ�� ��) ���ĺ��� ���ڰ� ���� �帥 �� ���� ����
*/
int main() {
	int i, n;
	time_t t;
	n = 5;
	
	/* Initalizes random number generator */
	srand((unsigned)time_t(&t));

	/* Print 5 random numbers from 0 to 49 */
	for (int i = 0; i < 5; i++) {
		printf("%d\n", rand() % 50);
	}


	srand(time(NULL)); // �� ���� rand�Լ� ȣ�� ���� �����ϸ�, �ð��� �������� �ʱ�ȭ�Ǵ� Real ������ ����� �� �� �ְ� �ȴ�. 

	for (int i = 0; i < 5; i++) {
		int random = rand() % 100; // 0 ~ 100 ������ ���� ����.
		cout << random << endl;
	}
	return(0);
}
