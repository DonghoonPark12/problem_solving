#include <iostream>
using namespace std;

class AAA {
private:
	int num1 =0;
public:												  // (C++�� C�� ���� �ణ�� �ӵ� ������ ����)
	virtual void Func1() { cout << "Func1" << '\n'; } //�Ѱ� �̻��� �����Լ��� �����ϴ� Ŭ������ ���ؼ��� �����Ϸ��� '�����Լ� ���̺�(V-Table)'�� ����. 
	virtual void Func2() { cout << "Func2" << '\n'; } //�� ��ü ������ ���ÿ� ���̺��� �����Ǵ°��� �ƴϰ�, ��ü ������ ��� ���� �޸� ������ �Ҵ�.
};

class BBB : public AAA {
private:
	int num2 =0;
public:
	virtual void Func1() { cout << "BBB::Func1" << '\n'; } //������, �������̵��� �����Լ��� �ּ������� ����Ŭ������ �����Լ� ���̺� �������� �ʴ´�. 
	void Func3() { cout << "Func3" << '\n'; }              //���� �������̵��� �����Լ��� ȣ���ϸ� ������! ���� �������� �������̵��� ����Ŭ���� ����Լ��� ȣ��Ǵ� ���̴�.
};

int main() {
	AAA* aptr = new AAA(); //Ŭ���� ������ ����
	aptr->Func1();

	BBB* bptr = new BBB();
	bptr->Func1();

	return 0;

}