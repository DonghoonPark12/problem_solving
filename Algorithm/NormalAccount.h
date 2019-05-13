/*
* 클래스 이름: NormalAccount.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/
#ifndef NORMAL_ACCOUNT_H 
#define NORMAL_ACCOUNT_H
#include "Account.h"

class NormalAccount : public Account {
private:
	int profitRate;
public:
	NormalAccount(int myid, int mywon, char *myname, int myRate)
		:Account(myid, mywon, myname), profitRate(myRate) 
	{ }

	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money*(profitRate / 100.0));
	 }
};
#endif // !1

