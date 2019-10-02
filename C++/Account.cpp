#include "BankingCommonDecl.h"
#include "Account.h"
#include <iostream>
using namespace std;

/*
* 파일 이름: Account.cpp
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/

Account::Account(int myid, int mywon, char *myname)
	:id(myid), won(mywon)
{
	name = new char[strlen(myname) + 1]; //myname이 자신의 크기만큼 공간을 할당 받아 객체 변수가 가리키게 한다. 
	strcpy(name, myname);
}

Account::Account(const Account &ref)  //복사 생성자
	:id(ref.id), won(ref.won)
{
	name = new char[strlen(ref.name) + 1]; //myname이 자신의 크기만큼 공간을 할당 받아 객체 변수가 가리키게 한다. 
	strcpy(name, ref.name);
}

Account& Account::operator=(const Account &acc)
{
	id = acc.id;
	won = acc.won;
	delete[]name;

	name = new char[strlen(acc.name) + 1];
	strcpy(name, acc.name);
	return *this;
}

int Account::GetID() const { return id; }

void Account::Deposit(int money) {
	won += money;
}

int Account::Withdraw(int money) {
	if (won < money)
		return 0;
	won -= money;
	return money;
}

inline void Account::ShowAccInfo() const
{
	cout << "계좌 ID:" << id << endl;
	cout << "이름:" << name << endl;
	cout << "잔액:" << won << endl;
}

Account::~Account() {
	delete[]name;
}
