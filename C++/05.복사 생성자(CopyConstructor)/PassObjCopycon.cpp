#include <iostream>
using namespace std;

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
	void ShowData() {
		cout << "num: " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob) {
	ob.ShowData();
}

int mani() {
	SoSimple obj(7);
	cout << "�Լ� ȣ�� ��" << endl;
	SimpleFuncObj(obj);
	cout << "�Լ� ȣ�� ��" << endl;
	return 0;
}