#ifndef FRUITSBUYER_H
#define FRUITSBUYER_H
#include <iostream>
using namespace std;

class FruitBuyer {
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money) 
		:myMoney(money), numOfApples(0)
	{
		//myMoney = money; //5000 -> 3000원
		//numOfApples = 0; //0 -> 2
	}
	bool BuyApples(FruitSeller &seller, int money) { //FruitSeller의 객체를 전달 받음, 2000
		if (money < 0) {
			cout << "잘못된 가격 전달" << endl;
			return false;
		}
		numOfApples += seller.SaleApples(money); //2000원을 전달, 2개를 리턴 받음
		myMoney -= money; //멤버 변수의 변화
		return true;
	}
	void ShowBuyResult() const {
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

#endif

