#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
using namespace std;

/*
1. 계좌 계설 할 때 마다 구조체가 새로 생성되어야 한다.
2. 구조체를 리스트 형태로 줄줄이 이으려고 한다.

취약점
- 아이디가 중복 될때 예외처리 안되있다.
- 목록에 없는 기능을 입력시 예외처리 안되있다. ex)5
- 입, 출금시 아이디 없는 곳에 접근시 예외처리 안되있다. -> 완료
*/

//typedef struct _account {
//	int id;
//	//string name;
//	char name[10];
//	int won;
//	struct _account *next;
//}account;

int main() {
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	AccountHandler manager;
	while (1) {
		manager.ShowMenu();

		cout << "선택: ";
		int choice; cin >> choice;

		switch(choice)
		{
		case MAKE:
			// AccountHandler::MakeAccount(); 객체를 정의하지 않고 함수를 호출(X)
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		}
		/*for (int i = 0; i < manager.GetAccount_num(); i++) {
			delete manager.acc[i];
		}*/ //필요 없다. 프로그램 종료가 되면 Account 객체의 소멸자 호출
	}

	return 0;
}



