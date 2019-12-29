#include "Account.h"
#include <iostream>
using namespace std;

/*
* ���� �̸�: Account.cpp
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/

Account::Account(int myid, int mybalance, char *myname)
	:accID(myid), balance(mybalance)
{
	name = new char[strlen(myname) + 1]; //myname�� �ڽ��� ũ�⸸ŭ ������ �Ҵ� �޾� ��ü ������ ����Ű�� �Ѵ�. 
	strcpy(name, myname);
}

Account::Account(const Account &ref)  //���� ������
	:accID(ref.accID), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1]; //myname�� �ڽ��� ũ�⸸ŭ ������ �Ҵ� �޾� ��ü ������ ����Ű�� �Ѵ�. 
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
	cout << "���� ID:" << accID << endl;
	cout << "�̸�:" << name << endl;
	cout << "�ܾ�:" << balance << endl;
}

Account::~Account() {
	delete[]name;
}
