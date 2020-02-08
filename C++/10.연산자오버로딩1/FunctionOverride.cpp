#include <iostream>>
using namespace std;

class First {
public:
	void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First {
public:
	void MyFunc() { cout << "Second Func" << endl; }
};

class Third : public Second {
public:
	void MyFunc() { cout << "Third Func" << endl; }
};

int main() {
	Third *tptr = new Third();
	Second *sptr = tptr; //�θ� Ŭ������ �����ͷ� �ڽ� ��ü �����͸� ����Ų��.
	First *fptr = sptr; //�θ� Ŭ������ �����ͷ� �ڽ� ��ü �����͸� ����Ų��.  

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	//sptr->FirstFunc();
	//sptr->SecondFunc();
	//sptr->ThirdFunc();

	//fptr->FirstFunc();
	//fptr->SecondFunc();
	//fptr->ThirdFunc();
}
