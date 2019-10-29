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
	:account_num(0)
{ }

void AccountHandler::ShowMenu() const
{
	cout << "\n------Menu-----" << "\n" <<
		"1.���� �輳" << "\n"
		<< "2.�Ա�" << "\n"
		<< "3.���" << "\n"
		<< "4. �������� ��ü ���" << "\n"
		<< "5. ���α׷� ����" << "\n" << endl;
}

void AccountHandler::MakeAccount() {
	int id;
	int won;
	char name[10];
	int rate;
	int credit;
	
	cout << "\n[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	int n; cin >> n;

	if (n == 1) {
		cout << "\n[���뿹�ݰ��� �輳]" << endl;
		cout << "���� ID: "; cin >> id;
		cout << "�̸�: "; cin >> name;
		cout << "�Աݾ�: "; cin >> won;
		cout << "������: "; cin >> rate;
		acc[account_num] = new NormalAccount(id, won, name, rate); //��ü �������� �����Ҵ�
		account_num++;
	}
	else if (n == 2) {
		cout << "\n[�ſ�ŷڰ��� �輳]" << endl;
		cout << "���� ID: "; cin >> id;
		cout << "�̸�: "; cin >> name;
		cout << "�Աݾ�: "; cin >> won;
		cout << "������: "; cin >> rate;
		cout << "�ſ���(1toA, 2toB, 3toC)"; cin >> credit;

		switch (credit) {
		case 1:
			acc[account_num++] = new HighCreditAccount(id, won, name, rate, CREDIT_LEVEL::CREDIT_A); //��ü �������� �����Ҵ�
			break;
		case 2:
			acc[account_num++] = new HighCreditAccount(id, won, name, rate, CREDIT_LEVEL::CREDIT_B); //��ü �������� �����Ҵ�
			break;
		case 3:
			acc[account_num++] = new HighCreditAccount(id, won, name, rate, CREDIT_LEVEL::CREDIT_C); //��ü �������� �����Ҵ�
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
}

void AccountHandler::DepositMoney()
{
	int tmpid;
	int tmpwon;

	cout << "\n[��   ��]" << endl;
	cout << "���� ID: "; cin >> tmpid;
	cout << "�Աݾ�: "; cin >> tmpwon;

	for (int i = 0; i < account_num; i++) {
		if (acc[i]->GetID() == tmpid) {  //����Լ��� ��������� ���� ����
			acc[i]->Deposit(tmpwon);
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

	for (int i = 0; i < account_num; i++) {
		if (acc[i]->GetID() == tmpid) {
			if (acc[i]->Withdraw(tmpwon) == 0) {
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
	for (int i = 0; i < account_num; i++) {
		//cout << "���� ID:" << acc[i]->GetID()<< endl;
		//cout << "�̸�:" << acc[i]->GetName()<< endl;
		//cout << "�ܾ�:" << acc[i]->GetWon()<< endl << endl;
		acc[i]->ShowAccInfo();
		cout << endl;
	}
	cout << "----------------" << endl;
}

AccountHandler::~AccountHandler(){
	for (int i = 0; i < account_num; i++)
		delete acc[i]; //Ŭ���� �迭���� ������ Ŭ������ ��ȯ�� ��
}
