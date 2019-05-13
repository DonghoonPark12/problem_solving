#ifndef ACCOUNT_H 
#define ACCOUNT_H
#include <string>
/*
	��������� Ŭ������ ������ ��´�. 
	��Ʈ�� Ŭ���� : ���α׷� ��ü ��� ���. ���α׷� ��ü ��ɰ� �帧�� �ľ��� �� �ִ�.
	Entity Ŭ���� : �������� ������ ���ϴ�. �������� ������ �ľ�.
*/

/*
* Ŭ���� �̸�: Account.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
* Ŭ���� ����: Entity Ŭ����
*/

class Account {
private:
	int id;
	char *name;
	int won;

public:
	Account(int myid, int mywon, char *myname);

	Account(const Account &ref);

	Account& operator=(const Account &acc);

	int GetID() const;

	//char GetName() { return *name; } �ʿ䰡 ��������.
	//int GetWon() { return won; } ���� : Account::ShowAccInfo()�Լ��� ��ü ������ ���� �����ϴ�, ������ �Լ��� ȣ���� ������ ����. Account::ShowAccInfo() ȣ�� �ϳ��� �ذ�ȴ�.

	virtual void Deposit(int money); // ����� ������ Ŭ������ �δ� �ʿ��� ����.

	int Withdraw(int money);
	
	void ShowAccInfo() const;

	~Account();
};

#endif // !OOPH
