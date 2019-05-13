/*
* 클래스 이름: HighCreditAccount.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/
#ifndef HIGH_CREDIT_ACCOUNT_H
#define HIGH_CREDIT_ACCOUNT_H
#include "NormalAccount.h"


class HighCreditAccount : public NormalAccount {
private:
	int Credit;
public:
	HighCreditAccount(int myid, int mywon, char *myname, int myRate, int myCredit)
		:NormalAccount(myid, mywon, myname, myRate), Credit(myCredit) {

	}
	virtual void Depositt(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money*(Credit / 100.0));
	}
};
#endif