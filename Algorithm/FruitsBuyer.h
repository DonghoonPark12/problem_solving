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
		//myMoney = money; //5000 -> 3000��
		//numOfApples = 0; //0 -> 2
	}
	bool BuyApples(FruitSeller &seller, int money) { //FruitSeller�� ��ü�� ���� ����, 2000
		if (money < 0) {
			cout << "�߸��� ���� ����" << endl;
			return false;
		}
		numOfApples += seller.SaleApples(money); //2000���� ����, 2���� ���� ����
		myMoney -= money; //��� ������ ��ȭ
		return true;
	}
	void ShowBuyResult() const {
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

#endif

