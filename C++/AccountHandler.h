/*
* Ŭ���� �̸�: AccountHandler.h
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
	//Account *acc[100]; //��ü ������ �迭�� ���� �޸� ����
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