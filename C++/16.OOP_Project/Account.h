#ifndef ACCOUNT_H 
#define ACCOUNT_H
//#include <string>

/*
* Ŭ���� �̸�: Account.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
* Ŭ���� ����: Entity Ŭ����
*/

class Account {
private:
	int accID;
	int balance;
	char *name;

public:
	Account(int myid, int mywon, char *myname);
	Account(const Account &ref);
	
	//Account& operator=(const Account &acc);
	int GetID() const;

	virtual void Deposit(int money); // ����� ������ Ŭ������ �δ� �ʿ��� ����.
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};
#endif // !OOPH
