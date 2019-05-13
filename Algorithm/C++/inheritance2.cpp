#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyFriendInfo {
private:
	char *name;
	int age;
public:
	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	MyFriendInfo(char *Myname, int Myage)
		:age(Myage)
	{
		name = new char[strlen(Myname) + 1];
		strcpy(name, Myname);
	}
	~MyFriendInfo()
	{
		delete[]name;
		cout << "Destructor MyFriendInfo" << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char *addr;
	char *phone;
public:
	MyFriendDetailInfo(char *Myname, int Myage, char *myaddr, char *myphone)
		:MyFriendInfo(Myname, Myage)
	{
		addr = new char[strlen(myaddr) + 1];
		phone = new char[strlen(myphone) + 1];
		strcpy(addr, myaddr);
		strcpy(phone, myphone);
	}
	void showFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "번호:" << phone << endl << endl;
	}
	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;
		cout << "Destructor MyFriendDetailInfo" << endl;
	}
};

int main() {
	MyFriendDetailInfo her("Hani", 24, "서울 관악구", "010 - 2232 - 4458");
	her.showFriendDetailInfo();
	return 0;
}