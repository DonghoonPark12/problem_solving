#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufacture;
	int printCount;//인쇄 매수
	int availableCount;//인쇄 종이 잔량
public:
	Printer(char *mo, char *ma, int n, int Count)
		:printCount(n), availableCount(Count) {
		//char *model = new char[sizeof(mo)];
		//char *manufacture = new char[sizeof(ma)];
		//strcpy(model, mo);
		//strcpy(manufacture, ma);
		model = mo; manufacture = ma;
	}
	string getModel() {
		return model;
	}
	string getManu() {
		return manufacture;
	}
	void print(int pages) {
		availableCount -= pages;
		printCount += pages;
	}
	int get_availableCount() {
		return availableCount;
	}
};

class InkJet : Printer {
	int Ink;
public:
	InkJet(char *mo, char *ma, int Count, int Ink)
		:Printer(mo, ma, 0, Count) { //남은 종이
		this->Ink = Ink; //남은 잉크
	}
	void show() {
		cout << getModel()<<" ,"<<getManu()<<" ,남은 종이 " << get_availableCount() << "장 ,남은 잉크 " << Ink << endl;
	}
	void printInkJet(int pages) {
		if (pages > get_availableCount()) {
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		}
		else {
			print(pages); //this->availableCount 감소
			Ink -= pages;//페이지수 만큼 잉크 감소
			cout << "프린트하였습니다." << endl;
		}
	}

};
class Laser : Printer {
	int Toner;
public:
	Laser(char *mo, char *ma, int Count, int Toner)
		:Printer(mo, ma, 0, Count) { //남은 종이
		this->Toner = Toner; //남은 토너 
	}
	void show() {
		cout << getModel()<<" ,"<<getManu()<<" ,남은 종이 " << get_availableCount() << "장 ,남은 잉크 " << Toner << endl;
	}
	void printLaser(int pages) {
		if (pages > get_availableCount()) {
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		}
		else {
			print(pages); //this->availableCount 감소
			Toner -= pages/2;//페이지수의 절반 만큼 잉크 감소
			cout << "프린트하였습니다." << endl;
		}
	}
};

int main() {
	//InkJet InkPrinter(5, 10); Laser LaserPrinter(3, 20);
	InkJet *IP = new InkJet("Officejet V40", "HP", 5, 10);
	Laser *LP = new Laser("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린트는 아래와 같다" << endl;
	//cout << "잉크젯 : OfficJet V40 .HP ,남은 종이 5장, 남은 잉크 10" << endl;
	//cout << "레이저: SCX-6x4, 삼성전자 ,남은 종이 3장, 남은 토너 20" << endl;
	cout << "잉크젯: "; IP->show();
	cout << "레이저: "; LP->show();


	int sel = 0, cnt = 0;
	char choice;
	while (1) {
		cout << endl<< "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> sel >> cnt;
		if (sel == 1){ //잉크젯
			IP->printInkJet(cnt);
		}
		else { //레이저
			LP->printLaser(cnt);
		}
		IP->show(); LP->show();

		cout << "계속 프린트 하시겠습니다(y/n)>>"; cin >> choice;
		if (choice == 'y')
			continue;
		else
			break;
	}
	return 0;
}