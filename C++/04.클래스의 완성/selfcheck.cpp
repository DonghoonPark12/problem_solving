#include <iostream>
using namespace std;
int main() {
	
	//int a = 20; //a�� stack
	//int &ref = a; //ref�� heap?? ���� �Ǵ� �ɷ� ������ stack

	int &ref = 20;//20�� heap�� ������� �ʴ´�. �׳� ������ ���� ����. 
	int b = (int)ref;
	
	cout << ref << '\n';
	cout << &ref << '\n';
	//cout << &a << '\n';
}