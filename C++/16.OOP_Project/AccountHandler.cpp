/*
* Ŭ���� �̸�: AccountHandler.cpp
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include <iostream>
using namespace std;

AccountHandler::AccountHandler()
	:accNum(0)
{ }

void AccountHandler::ShowMenu() const
{
	cout << "\n------Menu-----" << "\n" 
		<< "1.���� �輳" << "\n"
		<< "2.�Ա�" << "\n"
		<< "3.���" << "\n"
		<< "4. �������� ��ü ���" << "\n"
		<< "5. ���α׷� ����" << "\n" << endl;
}

void AccountHandler::MakeAccount() {
	cout << "\n[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	int sel; cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	cout << "[���뿹�ݰ��� �輳]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� �輳]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel) {
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

	/*
	���� ó���� MakeAccount �Լ��� ���ؼ� ��������� ������ �ߴµ�,
	�����ڸ� ���� �ٷ� ��ü �ʱ�ȭ �ϸ� �ȴ�.
	*/
	//id = tmpid;
	//name = new char[strlen(tmpname) + 1];
	//strcpy(name, tmpname);
	//won = tmpwon;


void AccountHandler::DepositMoney()
{
	int tmpid;
	int tmpwon;

	cout << "\n[��   ��]" << endl;
	cout << "���� ID: "; cin >> tmpid;
	cout << "�Աݾ�: "; cin >> tmpwon;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetID() == tmpid) {  //����Լ��� ��������� ���� ����
			accArr[i]->Deposit(tmpwon);
			cout << "�Ա� �Ϸ�!\n";
			return;//ã���� �Լ� ���� ���ѹ����� �ȴ�. break; �� �ƴ϶�.
		}
	}
	cout << "�������� �ʴ� ���� ID �Դϴ�." << endl;
}

void AccountHandler::WithdrawMoney()
{
	int tmpid;
	int tmpwon;

	cout << "\n[��   ��]" << endl;
	cout << "���� ID: "; cin >> tmpid;
	cout << "��ݾ�: "; cin >> tmpwon;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetID() == tmpid) {
			if (accArr[i]->Withdraw(tmpwon) == 0) {
				cout << "�ܾ� ����" << endl << endl;
				return;
			}
			cout << "��� �Ϸ�!\n";
			return;
		}
	}
	cout << "�������� �ʴ� ���� ID �Դϴ�." << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const {
	cout << "----------------" << endl;
	cout << "[��ü ���� ����]" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
	cout << "----------------" << endl;
}

AccountHandler::~AccountHandler(){
	for (int i = 0; i < accNum; i++)
		delete accArr[i]; //Ŭ���� �迭���� ������ Ŭ������ ��ȯ�� ��
}
