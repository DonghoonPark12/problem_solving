#include "Account.h"
#include <iostream>
using namespace std;

/*
* 파일 이름: Account.cpp
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/

Account::Account(int myid, int mybalance, char *myname)
	:accID(myid), balance(mybalance)
{
	name = new char[strlen(myname) + 1]; //myname이 자신의 크기만큼 공간을 할당 받아 객체 변수가 가리키게 한다. 
	strcpy(name, myname);
}

Account::Account(const Account &ref)  //복사 생성자
	:accID(ref.accID), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1]; //myname이 자신의 크기만큼 공간을 할당 받아 객체 변수가 가리키게 한다. 
	strcpy(name, ref.name);
}

//Account& Account::operator=(const Account &acc)
//{
//	accID = acc.accID;
//	balance = acc.balance;
//	delete[]name;
//
//	name = new char[strlen(acc.name) + 1];
//	strcpy(name, acc.name);
//	return *this;
//}

int Account::GetID() const { return accID; }

void Account::Deposit(int money) {
	balance += money;
}

int Account::Withdraw(int money) {
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}

inline void Account::ShowAccInfo() const
{
	cout << "계좌 ID:" << accID << endl;
	cout << "이름:" << name << endl;
	cout << "잔액:" << balance << endl;
}

Account::~Account() {
	delete[]name;
}
