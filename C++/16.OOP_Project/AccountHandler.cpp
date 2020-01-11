/*
* 클래스 이름: AccountHandler.cpp
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
		<< "1.계좌 계설" << "\n"
		<< "2.입금" << "\n"
		<< "3.출급" << "\n"
		<< "4. 계좌정보 전체 출력" << "\n"
		<< "5. 프로그램 종료" << "\n" << endl;
}

void AccountHandler::MakeAccount() {
	cout << "\n[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
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
	cout << "[보통예금계좌 계설]" << endl;
	cout << "계좌 ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 계설]" << endl;
	cout << "계좌 ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
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
	나는 처음에 MakeAccount 함수를 통해서 멤버변수에 접근을 했는데,
	생성자를 통해 바로 객체 초기화 하면 된다.
	*/
	//id = tmpid;
	//name = new char[strlen(tmpname) + 1];
	//strcpy(name, tmpname);
	//won = tmpwon;


void AccountHandler::DepositMoney()
{
	int tmpid;
	int tmpwon;

	cout << "\n[입   금]" << endl;
	cout << "계좌 ID: "; cin >> tmpid;
	cout << "입금액: "; cin >> tmpwon;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetID() == tmpid) {  //멤버함수는 멤버변수에 접근 가능
			accArr[i]->Deposit(tmpwon);
			cout << "입금 완료!\n";
			return;//찾으면 함수 종료 시켜버리면 된다. break; 가 아니라.
		}
	}
	cout << "존재하지 않는 계좌 ID 입니다." << endl;
}

void AccountHandler::WithdrawMoney()
{
	int tmpid;
	int tmpwon;

	cout << "\n[출   금]" << endl;
	cout << "계좌 ID: "; cin >> tmpid;
	cout << "출금액: "; cin >> tmpwon;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetID() == tmpid) {
			if (accArr[i]->Withdraw(tmpwon) == 0) {
				cout << "잔액 부족" << endl << endl;
				return;
			}
			cout << "출금 완료!\n";
			return;
		}
	}
	cout << "존재하지 않는 계좌 ID 입니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const {
	cout << "----------------" << endl;
	cout << "[전체 계좌 정보]" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
	cout << "----------------" << endl;
}

AccountHandler::~AccountHandler(){
	for (int i = 0; i < accNum; i++)
		delete accArr[i]; //클래스 배열에서 각각의 클래스를 반환할 때
}
