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
	:account_num(0)
{ }

void AccountHandler::ShowMenu() const
{
	cout << "\n------Menu-----" << "\n" <<
		"1.계좌 계설" << "\n"
		<< "2.입금" << "\n"
		<< "3.출급" << "\n"
		<< "4. 계좌정보 전체 출력" << "\n"
		<< "5. 프로그램 종료" << "\n" << endl;
}

void AccountHandler::MakeAccount() {
	int id;
	int won;
	char name[10];
	int rate;
	int credit;
	
	cout << "\n[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	int n; cin >> n;

	if (n == 1) {
		cout << "\n[보통예금계좌 계설]" << endl;
		cout << "계좌 ID: "; cin >> id;
		cout << "이름: "; cin >> name;
		cout << "입금액: "; cin >> won;
		cout << "이자율: "; cin >> rate;
		acc[account_num] = new NormalAccount(id, won, name, rate); //객체 포인터의 동적할당
		account_num++;
	}
	else if (n == 2) {
		cout << "\n[신용신뢰계좌 계설]" << endl;
		cout << "계좌 ID: "; cin >> id;
		cout << "이름: "; cin >> name;
		cout << "입금액: "; cin >> won;
		cout << "이자율: "; cin >> rate;
		cout << "신용등급(1toA, 2toB, 3toC)"; cin >> credit;

		switch (credit) {
		case 1:
			acc[account_num++] = new HighCreditAccount(id, won, name, rate, CREDIT_LEVEL::CREDIT_A); //객체 포인터의 동적할당
			break;
		case 2:
			acc[account_num++] = new HighCreditAccount(id, won, name, rate, CREDIT_LEVEL::CREDIT_B); //객체 포인터의 동적할당
			break;
		case 3:
			acc[account_num++] = new HighCreditAccount(id, won, name, rate, CREDIT_LEVEL::CREDIT_C); //객체 포인터의 동적할당
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
}

void AccountHandler::DepositMoney()
{
	int tmpid;
	int tmpwon;

	cout << "\n[입   금]" << endl;
	cout << "계좌 ID: "; cin >> tmpid;
	cout << "입금액: "; cin >> tmpwon;

	for (int i = 0; i < account_num; i++) {
		if (acc[i]->GetID() == tmpid) {  //멤버함수는 멤버변수에 접근 가능
			acc[i]->Deposit(tmpwon);
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

	for (int i = 0; i < account_num; i++) {
		if (acc[i]->GetID() == tmpid) {
			if (acc[i]->Withdraw(tmpwon) == 0) {
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
	for (int i = 0; i < account_num; i++) {
		//cout << "계좌 ID:" << acc[i]->GetID()<< endl;
		//cout << "이름:" << acc[i]->GetName()<< endl;
		//cout << "잔액:" << acc[i]->GetWon()<< endl << endl;
		acc[i]->ShowAccInfo();
		cout << endl;
	}
	cout << "----------------" << endl;
}

AccountHandler::~AccountHandler(){
	for (int i = 0; i < account_num; i++)
		delete acc[i]; //클래스 배열에서 각각의 클래스를 반환할 때
}
