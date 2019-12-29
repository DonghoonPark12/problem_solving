#define	_CRT_SECURE_NO_WARNINGS

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

/*
1. ���� �輳 �� �� ���� ����ü�� ���� �����Ǿ�� �Ѵ�.
2. ����ü�� ����Ʈ ���·� ������ �������� �Ѵ�.

�����
- ���̵� �ߺ� �ɶ� ����ó�� �ȵ��ִ�.
- ��Ͽ� ���� ����� �Է½� ����ó�� �ȵ��ִ�. ex)5
- ��, ��ݽ� ���̵� ���� ���� ���ٽ� ����ó�� �ȵ��ִ�. -> �Ϸ�
*/


int main() {
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
		default:
			cout << "Ileegal selection!" << '\n';
		}
	}
	return 0;
}



