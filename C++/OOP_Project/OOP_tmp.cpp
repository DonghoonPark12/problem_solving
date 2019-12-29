#include <iostream>
#include <string>
using namespace std;
const int NAME_LEN = 20;

/*
	��������� Ŭ������ ������ ��´�.
	��Ʈ�� Ŭ���� : ���α׷� ��ü ��� ���. ���α׷� ��ü ��ɰ� �帧�� �ľ��� �� �ִ�.
	Entity Ŭ���� : �������� ������ ���ϴ�. �������� ������ �ľ�.
*/

//���α׷� ������� ���� �޴�
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//�ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//������ ����
enum { NORMAL = 1, CREDIT = 2 };

/*
* Ŭ������ �̸� : Account
* Ŭ������ ���� : Entity Ŭ����
*/

class Account {
private:
	int accID;
	int balance;
	char* name;

public:
	Account(int myid, int mywon, char* myname);
	Account(const Account& ref);

	Account& operator=(const Account& acc);
	
	int GetID() const;
	virtual void Deposit(int money); // ����� ������ Ŭ������ �δ� �ʿ��� ����.
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account(int myid, int mybalance, char* myname)
	:accID(myid), balance(mybalance)
{
	name = new char[strlen(myname) + 1]; //myname�� �ڽ��� ũ�⸸ŭ ������ �Ҵ� �޾� ��ü ������ ����Ű�� �Ѵ�. 
	strcpy(name, myname);
}

Account::Account(const Account& ref)  //���� ������
	:accID(ref.accID), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1]; //myname�� �ڽ��� ũ�⸸ŭ ������ �Ҵ� �޾� ��ü ������ ����Ű�� �Ѵ�. 
	strcpy(name, ref.name);
}

int Account::GetID() const { return accID; }

void Account::Deposit(int money) {
	balance += money;
}

int Account::Withdraw(int money) {
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}

inline void Account::ShowAccInfo() const{
	cout << "���� ID:" << accID << endl;
	cout << "�̸�:" << name << endl;
	cout << "�ܾ�:" << balance << endl;
}

/*
* Ŭ������ �̸� : NormalAccount
* Ŭ������ ���� : Entity Ŭ����
*/

class NormalAccount : public Account {
private:
	int profitRate;
public:
	NormalAccount(int myid, int mywon, char* myname, int myRate)
		:Account(myid, mywon, myname), profitRate(myRate)
	{ }

	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money * (profitRate / 100.0));
	}
};

/*
* Ŭ������ �̸� : HighCreditAccount
* Ŭ������ ���� : Entity Ŭ����
*/

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int myid, int mywon, char* myname, int rate, int special)
		:NormalAccount(myid, mywon, myname, rate), specialRate(special)
	{ }
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}
};


/*
* Ŭ������ �̸� : AccountHandler
* Ŭ������ ���� : Control Ŭ����
*/

class AccountHandler {
private:
	int accNum;
	Account *accArr[100]; //��ü ������ �迭�� ���� �޸� ����
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

void AccountHandler::DepositMoney(){
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

void AccountHandler::WithdrawMoney(){
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

AccountHandler::AccountHandler()
	:accNum(0)
{ }

void AccountHandler::ShowAllAccInfo() const {
	cout << "----------------" << endl;
	cout << "[��ü ���� ����]" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
	cout << "----------------" << endl;
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete accArr[i]; //Ŭ���� �迭���� ������ Ŭ������ ��ȯ�� ��
}


int main() {
	AccountHandler manager;
	int choice;

	while (1) {
		manager.ShowMenu();
		cout << "����: "; cin >> choice; cout << '\n';
		switch (choice) {
		case MAKE:
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
		case EXIT:
			return 0;
		default:
			cout << "Ileegal selection!" << '\n';
		}
	}
	return 0;
}


