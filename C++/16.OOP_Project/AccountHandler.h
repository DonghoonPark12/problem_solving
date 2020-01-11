#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H
#include "Account.h"
//#include "AccountArray.h"
/*
* Ŭ���� �̸�: AccountHandler.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/
class AccountHandler {
private:
	int accNum;
	Account* accArr[100]; //��ü ������ �迭�� ���� �޸� ����
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};
#endif