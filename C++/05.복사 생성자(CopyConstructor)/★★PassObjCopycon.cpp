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
	SoSimple(const SoSimple& copy)//원본 객체의 변경을 막기위해 const 키워드를 사용한다. 
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

//Call by value이기 때문에 새로운 객체 ob가 생성되고 따라서,
//파라미터 ob의 복사 생성자가 호출된다. 
SoSimple SimpleFuncObj(const SoSimple ob) {
	ob.ShowData();
	return ob;
}

//Call by reference이며 ob는 obj의 nickname일 뿐이다. 따라서,
//파라미터 ob의 복사 생성자는 호출되지 않는다. 
SoSimple SimpleFuncObj2(const SoSimple& ob) {
	ob.ShowData();
	return ob;
}

int main() {
	SoSimple obj(7);
	cout << "함수 호출 전" << endl;
	SoSimple ob2 = SimpleFuncObj(obj);
	SoSimple ob3 = SimpleFuncObj2(obj);
	cout << "함수 호출 후" << endl;
	return 0;
}

/*
	함수 호출 전
	Called SoSimple(const Sosimple& copy)
	num: 7
	Called SoSimple(const Sosimple& copy)
	call destructor!
	num: 7
	Called SoSimple(const Sosimple& copy)
	함수 호출 후
*/