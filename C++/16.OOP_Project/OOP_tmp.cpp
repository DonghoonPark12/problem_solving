#include <iostream>
#include <string>
using namespace std;
const int NAME_LEN = 20;

/*
	헤더파일은 클래스의 선언을 담는다.
	컨트롤 클래스 : 프로그램 전체 기능 담당. 프로그램 전체 기능과 흐름을 파악할 수 있다.
	Entity 클래스 : 데이터적 성격이 강하다. 데이터의 종류를 파악.
*/

//프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };

/*
* 클래스의 이름 : Account
* 클래스의 유형 : Entity 클래스
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
	virtual void Deposit(int money); // 기능적 성격의 클래스를 두니 필요해 졌다.
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account(int myid, int mybalance, char* myname)
	:accID(myid), balance(mybalance)
{
	name = new char[strlen(myname) + 1]; //myname이 자신의 크기만큼 공간을 할당 받아 객체 변수가 가리키게 한다. 
	strcpy(name, myname);
}

Account::Account(const Account& ref)  //복사 생성자
	:accID(ref.accID), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1]; //myname이 자신의 크기만큼 공간을 할당 받아 객체 변수가 가리키게 한다. 
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
	cout << "계좌 ID:" << accID << endl;
	cout << "이름:" << name << endl;
	cout << "잔액:" << balance << endl;
}

/*
* 클래스의 이름 : NormalAccount
* 클래스의 유형 : Entity 클래스
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
* 클래스의 이름 : HighCreditAccount
* 클래스의 유형 : Entity 클래스
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
* 클래스의 이름 : AccountHandler
* 클래스의 유형 : Control 클래스
*/

class AccountHandler {
private:
	int accNum;
	Account *accArr[100]; //객체 포인터 배열을 통해 메모리 절감
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

void AccountHandler::DepositMoney(){
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

void AccountHandler::WithdrawMoney(){
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

AccountHandler::AccountHandler()
	:accNum(0)
{ }

void AccountHandler::ShowAllAccInfo() const {
	cout << "----------------" << endl;
	cout << "[전체 계좌 정보]" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
	cout << "----------------" << endl;
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete accArr[i]; //클래스 배열에서 각각의 클래스를 반환할 때
}


int main() {
	AccountHandler manager;
	int choice;

	while (1) {
		manager.ShowMenu();
		cout << "선택: "; cin >> choice; cout << '\n';
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


