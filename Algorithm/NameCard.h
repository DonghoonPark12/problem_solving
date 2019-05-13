#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

namespace COMP_POS {
	enum {CLERK, SENIOR, ASSIST, MANAGER};
	void showPosition(int pos) {
		switch (pos) {
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}

	}
}
class NameCard
{
	char *name;
	char *corp;
	char *PhoneNum;
	int pos;

public:
	NameCard(char *myname, char *mycorp, char *myPhoneNum, int Mypos)
		//:name(myname), corp(mycorp), PhoneNum(myPhoneNum), pos(Mypos) 문자열 이니셜라이즈 이렇게 안한다. 
		:pos(Mypos)
	{
		name = new char[strlen(myname) + 1]; //공간 할당
		strcpy(name, myname);
		corp = new char[strlen(mycorp) + 1]; //공간 할당
		strcpy(corp, mycorp);
		PhoneNum = new char[strlen(myPhoneNum) + 1]; //공간 할당
		strcpy(PhoneNum, myPhoneNum);
	}
	NameCard(const NameCard &copy)
		:pos(copy.pos)
	{
		name = new char[strlen(copy.name) + 1]; //공간 할당
		strcpy(name, copy.name);
		corp = new char[strlen(copy.corp) + 1]; //공간 할당
		strcpy(corp, copy.corp);
		PhoneNum = new char[strlen(copy.PhoneNum) + 1]; //공간 할당
		strcpy(PhoneNum, copy.PhoneNum);
	}

	void ShowNameCardInfo() {
		cout << "이름: "     << name << endl;
		cout << "회사: "     << corp << endl;
		cout << "전화번호: " << PhoneNum << endl;
		cout << "직급: "; COMP_POS::showPosition(pos);
		cout << endl;
	}
	~NameCard() {
		delete []name;
		delete []corp;
		delete []PhoneNum;
		cout << "call destructor!" << endl;
	}
};

