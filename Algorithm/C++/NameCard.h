#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

namespace COMP_POS {
	enum {CLERK, SENIOR, ASSIST, MANAGER};
	void showPosition(int pos) {
		switch (pos) {
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
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
		//:name(myname), corp(mycorp), PhoneNum(myPhoneNum), pos(Mypos) ���ڿ� �̴ϼȶ����� �̷��� ���Ѵ�. 
		:pos(Mypos)
	{
		name = new char[strlen(myname) + 1]; //���� �Ҵ�
		strcpy(name, myname);
		corp = new char[strlen(mycorp) + 1]; //���� �Ҵ�
		strcpy(corp, mycorp);
		PhoneNum = new char[strlen(myPhoneNum) + 1]; //���� �Ҵ�
		strcpy(PhoneNum, myPhoneNum);
	}
	NameCard(const NameCard &copy)
		:pos(copy.pos)
	{
		name = new char[strlen(copy.name) + 1]; //���� �Ҵ�
		strcpy(name, copy.name);
		corp = new char[strlen(copy.corp) + 1]; //���� �Ҵ�
		strcpy(corp, copy.corp);
		PhoneNum = new char[strlen(copy.PhoneNum) + 1]; //���� �Ҵ�
		strcpy(PhoneNum, copy.PhoneNum);
	}

	void ShowNameCardInfo() {
		cout << "�̸�: "     << name << endl;
		cout << "ȸ��: "     << corp << endl;
		cout << "��ȭ��ȣ: " << PhoneNum << endl;
		cout << "����: "; COMP_POS::showPosition(pos);
		cout << endl;
	}
	~NameCard() {
		delete []name;
		delete []corp;
		delete []PhoneNum;
		cout << "call destructor!" << endl;
	}
};

