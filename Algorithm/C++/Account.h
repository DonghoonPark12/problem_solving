#ifndef ACCOUNT_H 
#define ACCOUNT_H
#include <string>
/*
	헤더파일은 클래스의 선언을 담는다. 
	컨트롤 클래스 : 프로그램 전체 기능 담당. 프로그램 전체 기능과 흐름을 파악할 수 있다.
	Entity 클래스 : 데이터적 성격이 강하다. 데이터의 종류를 파악.
*/

/*
* 클래스 이름: Account.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
* 클래스 유형: Entity 클래스
*/

class Account {
private:
	int id;
	char *name;
	int won;

public:
	Account(int myid, int mywon, char *myname);

	Account(const Account &ref);

	Account& operator=(const Account &acc);

	int GetID() const;

	//char GetName() { return *name; } 필요가 없어졌다.
	//int GetWon() { return won; } 사유 : Account::ShowAccInfo()함수가 객체 변수에 직접 접근하니, 각각의 함수를 호출할 이유가 없다. Account::ShowAccInfo() 호출 하나로 해결된다.

	virtual void Deposit(int money); // 기능적 성격의 클래스를 두니 필요해 졌다.

	int Withdraw(int money);
	
	void ShowAccInfo() const;

	~Account();
};

#endif // !OOPH
