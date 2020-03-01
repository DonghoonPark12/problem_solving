#include <iostream>
using namespace std;
/*
	https://stackoverflow.com/questions/16728441/why-is-the-copy-constructor-called-when-we-pass-an-object-as-an-argument-by-valu?rq=1
*/
class SoSimple {
private:
	int num;
public:
	SoSimple(int n)
		:num(n)
	{}
	SoSimple(const SoSimple& copy)//���� ��ü�� ������ �������� const Ű���带 ����Ѵ�. 
		:num(copy.num)
	{
		cout << "Called SoSimple(const Sosimple& copy)" << endl;
	}
	void ShowData() const {
		cout << "num: " << num << endl;
	}
	~SoSimple() {
		cout << "call destructor!" << endl;
	}
};

//Call by value�̱� ������ ���ο� ��ü ob�� �����ǰ� ����,
//�Ķ���� ob�� ���� �����ڰ� ȣ��ȴ�. 
SoSimple SimpleFuncObj(const SoSimple ob) {
	ob.ShowData();
	return ob;
}

//Call by reference�̸� ob�� obj�� nickname�� ���̴�. ����,
//�Ķ���� ob�� ���� �����ڴ� ȣ����� �ʴ´�. 
SoSimple SimpleFuncObj2(const SoSimple& ob) {
	ob.ShowData();
	return ob;
}

int main() {
	SoSimple obj(7);
	cout << "�Լ� ȣ�� ��" << endl;
	SoSimple ob2 = SimpleFuncObj(obj);
	SoSimple ob3 = SimpleFuncObj2(obj);
	cout << "�Լ� ȣ�� ��" << endl;
	return 0;
}

/*
	�Լ� ȣ�� ��
	Called SoSimple(const Sosimple& copy)
	num: 7
	Called SoSimple(const Sosimple& copy)
	call destructor!
	num: 7
	Called SoSimple(const Sosimple& copy)
	�Լ� ȣ�� ��
*/