#include <iostream>
using namespace std;

class Car {
private:
	int gasolineGauge;
public:
	int GetGasGauge() {
		return gasolineGauge;
	}
	Car(int gas)
		:gasolineGauge(gas)
	{ }
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	int GetElecGauge() {
		return electricGauge;
	}
	HybridCar(int elec, int gas)
		:Car(gas), electricGauge(elec)
	{ }
};

class HybridWaterCar : public HybridCar {
private:
	int waterGuage;
public:
	void ShowCurrentGauge() {
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGuage << endl;
	}
	HybridWaterCar(int water, int elec, int gas)
		:HybridCar(elec, gas), waterGuage(water)
	{ }
};

int main() {
	HybridWaterCar wCar(50000, 1000, 2000);
	wCar.ShowCurrentGauge();
}
