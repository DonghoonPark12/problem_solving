#include "BankingCommonDecl.h"
#include "Account.h"
#include <iostream>
using namespace std;

/*
* ���� �̸�: Account.cpp
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/

Account::Account(int myid, int mywon, char *myname)
	:id(myid), won(mywon)
{
	name = new char[strlen(myname) + 1]; //myname�� �ڽ��� ũ�⸸ŭ ������ �Ҵ� �޾� ��ü ������ ����Ű�� �Ѵ�. 
	strcpy(name, myname);
}

Account::Account(const Account &ref)  //���� ������
	:id(ref.id), won(ref.won)
{
	name = new char[strlen(ref.name) + 1]; //myname�� �ڽ��� ũ�⸸ŭ ������ �Ҵ� �޾� ��ü ������ ����Ű�� �Ѵ�. 
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
	cout << "���� ID:" << id << endl;
	cout << "�̸�:" << name << endl;
	cout << "�ܾ�:" << won << endl;
}

Account::~Account() {
	delete[]name;
}
