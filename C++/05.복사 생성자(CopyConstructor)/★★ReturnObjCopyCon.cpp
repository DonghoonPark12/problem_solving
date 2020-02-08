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
	SoSimple& AddNum(int n) {
		num += n;
		return *this;
	}
	void ShowData() {
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {
	cout << "return ����" << endl;
	return ob;
}

int main() {
	SoSimple obj(7);
	SoSimple(obj).AddNum(30).ShowData();
	obj.ShowData();
	return 0;
}

