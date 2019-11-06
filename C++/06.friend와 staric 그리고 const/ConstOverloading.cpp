#include <iostream>
using namespace std;

class SoSimple{
private:
	int num;
public:
	SoSimple(int n): num(n)
	{ }
	SoSimple &AddNum(int n) {
		num += n;
		return *this;
	}
	void SimpleFunc() {
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const { //const ���� ������ �Լ� �����ε� ���ǿ� �ش��Ѵ�. 
		cout << "Const SimpleFunc: " << num << endl;
	}
};

void YouFunc(const SoSimple &obj) { //Const �����ڿ� ���� ��ü����(�����ϰ�, ���ɵ� ����).
	obj.SimpleFunc();
}

int main() {
	SoSimple obj1(2);        
	const SoSimple obj2(7); //�Ϲ� ��ü�� const��ü�� ���� ����

	obj1.SimpleFunc();
	obj2.SimpleFunc(); //���(const)��ü�� const ����Լ� ���� ȣ���� �� �ִ�.

	YouFunc(obj1); //const ����Լ� ȣ��
	YouFunc(obj2); //const ����Լ� ȣ��

	return 0;
}