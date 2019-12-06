#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n)
		:num(n)
	{}
	SoSimple(const SoSimple& copy)//원본 객체의 변경을 막기위해 const 키워드를 사용한다. 
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
	cout << "함수 호출 전" << endl;
	SimpleFuncObj(obj);
	cout << "함수 호출 후" << endl;
	return 0;
}