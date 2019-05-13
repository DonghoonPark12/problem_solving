/*
* 클래스 이름: AccountHandler.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/
#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H
#include "Account.h"
#include "AccountArray.h"
class AccountHandler {
private:
	int account_num;
	//Account *acc[100]; //객체 포인터 배열을 통해 메모리 절감
	//Account *acc;
	BoundCheckPointArr acc;
public:
	AccountHandler();
	//int& operator[](int idx);
	int GetAccount_num() const { return account_num; }
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
}; 
#endif