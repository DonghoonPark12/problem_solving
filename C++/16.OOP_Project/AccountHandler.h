#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H
#include "Account.h"
//#include "AccountArray.h"
/*
* 클래스 이름: AccountHandler.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/
class AccountHandler {
private:
	int accNum;
	Account* accArr[100]; //객체 포인터 배열을 통해 메모리 절감
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