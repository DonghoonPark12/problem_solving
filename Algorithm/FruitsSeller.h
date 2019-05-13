#ifndef FRUITSSELLER_H
#define FRUITSSELLER_H
#include <iostream>
using namespace std;

class FruitSeller {
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money)
		:APPLE_PRICE(price), numOfApples(num), myMoney(money) //이니셜라이져로 멤버 변수 초기화 가능
	{
		//APPLE_PRICE = price;
		//numOfApples = num;
		//myMoney = money;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num; //20 -> 18개 
		myMoney += money; //0 -> 2000원
		return num;
	}
	void ShowSalesResult() const {
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl;
	}
};
#endif