#include <iostream>

int main() {
	const int num = 12;

	const int *ptr = &num;//const ������ �����ͷ� ����ų �� const �ٿ���� �Ѵ�. 
	const int *(&pref) = ptr; //const�� ����� ������ ������ �����ϴ� �����ڸ� ���� �� ������ const�� �ٿ���� �Ѵ�.

	std::cout << *ptr << std::endl;
	std::cout << *(pref) << std::endl; //������ ������ �ٸ� �̸�
}