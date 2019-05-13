#include <iostream>
#include "FruitsSeller.h"
#include "FruitsBuyer.h"
using namespace std;

int main() {
	FruitSeller seller(1000, 20, 0); //APPLE_PRICE == 1000, ������ �ִ� ��� ���� 20��
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000); //2000�� ġ�� ���. 

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}