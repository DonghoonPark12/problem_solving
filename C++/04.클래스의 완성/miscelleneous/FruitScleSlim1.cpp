#include <iostream>
#include "FruitsSeller.h"
#include "FruitsBuyer.h"
using namespace std;

int main() {
	FruitSeller seller(1000, 20, 0); //APPLE_PRICE == 1000, 가지고 있는 사과 갯수 20개
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000); //2000원 치를 산다. 

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}