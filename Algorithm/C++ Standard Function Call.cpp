#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
srand�� ȣ���� �� ���޹��� ���ڸ� ������� ������ �ʱ�ȭ
rand�� srand�� ���� ������ ���� �������� ������ ����.
time �Լ��� ���ڰ����� NULL�� �ѱ�� 1970�� 1�� 1�� 0��(UTC Ÿ�� ��) ���ĺ��� ���ڰ� ���� �帥 �� ���� ����
*/
int main() {
	srand(time(NULL)); // �� ���� rand�Լ� ȣ�� ���� �����ϸ�, �ð��� �������� �ʱ�ȭ�Ǵ� Real ������ ����� �� �� �ְ� �ȴ�. 
	
	for (int i = 0; i < 5; i++) {
		int random = rand() % 100; // 0 ~ 100 ������ ���� ����.
		cout << random << endl;
	}
	
}