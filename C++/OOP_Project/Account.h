#ifndef ACCOUNT_H 
#define ACCOUNT_H
//#include <string>

/*
* 클래스 이름: Account.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
* 클래스 유형: Entity 클래스
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

	virtual void Deposit(int money); // 기능적 성격의 클래스를 두니 필요해 졌다.
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};
#endif // !OOPH
