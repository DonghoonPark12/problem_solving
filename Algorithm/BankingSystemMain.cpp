#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
using namespace std;

/*
1. ���� �輳 �� �� ���� ����ü�� ���� �����Ǿ�� �Ѵ�.
2. ����ü�� ����Ʈ ���·� ������ �������� �Ѵ�.

�����
- ���̵� �ߺ� �ɶ� ����ó�� �ȵ��ִ�.
- ��Ͽ� ���� ����� �Է½� ����ó�� �ȵ��ִ�. ex)5
- ��, ��ݽ� ���̵� ���� ���� ���ٽ� ����ó�� �ȵ��ִ�. -> �Ϸ�
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

		cout << "����: ";
		int choice; cin >> choice;

		switch(choice)
		{
		case MAKE:
			// AccountHandler::MakeAccount(); ��ü�� �������� �ʰ� �Լ��� ȣ��(X)
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
		}*/ //�ʿ� ����. ���α׷� ���ᰡ �Ǹ� Account ��ü�� �Ҹ��� ȣ��
	}

	return 0;
}



