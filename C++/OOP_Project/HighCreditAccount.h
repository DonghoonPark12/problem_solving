#ifndef HIGHCREDIT_ACCOUNT_H 
#define HIGHCREDIT_ACCOUNT_H
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int myid, int mywon, char* myname, int rate, int special)
		:NormalAccount(myid, mywon, myname, rate), specialRate(special)
	{ }
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}
};
#endif