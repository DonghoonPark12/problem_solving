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
		:APPLE_PRICE(price), numOfApples(num), myMoney(money) //�̴ϼȶ������� ��� ���� �ʱ�ȭ ����
	{
		//APPLE_PRICE = price;
		//numOfApples = num;
		//myMoney = money;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num; //20 -> 18�� 
		myMoney += money; //0 -> 2000��
		return num;
	}
	void ShowSalesResult() const {
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl;
	}
};
#endif