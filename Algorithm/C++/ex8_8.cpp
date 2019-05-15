#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufacture;
	int printCount;//�μ� �ż�
	int availableCount;//�μ� ���� �ܷ�
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
		:Printer(mo, ma, 0, Count) { //���� ����
		this->Ink = Ink; //���� ��ũ
	}
	void show() {
		cout << getModel()<<" ,"<<getManu()<<" ,���� ���� " << get_availableCount() << "�� ,���� ��ũ " << Ink << endl;
	}
	void printInkJet(int pages) {
		if (pages > get_availableCount()) {
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
		else {
			print(pages); //this->availableCount ����
			Ink -= pages;//�������� ��ŭ ��ũ ����
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
	}

};
class Laser : Printer {
	int Toner;
public:
	Laser(char *mo, char *ma, int Count, int Toner)
		:Printer(mo, ma, 0, Count) { //���� ����
		this->Toner = Toner; //���� ��� 
	}
	void show() {
		cout << getModel()<<" ,"<<getManu()<<" ,���� ���� " << get_availableCount() << "�� ,���� ��ũ " << Toner << endl;
	}
	void printLaser(int pages) {
		if (pages > get_availableCount()) {
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
		else {
			print(pages); //this->availableCount ����
			Toner -= pages/2;//���������� ���� ��ŭ ��ũ ����
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
	}
};

int main() {
	//InkJet InkPrinter(5, 10); Laser LaserPrinter(3, 20);
	InkJet *IP = new InkJet("Officejet V40", "HP", 5, 10);
	Laser *LP = new Laser("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2���� ����Ʈ�� �Ʒ��� ����" << endl;
	//cout << "��ũ�� : OfficJet V40 .HP ,���� ���� 5��, ���� ��ũ 10" << endl;
	//cout << "������: SCX-6x4, �Ｚ���� ,���� ���� 3��, ���� ��� 20" << endl;
	cout << "��ũ��: "; IP->show();
	cout << "������: "; LP->show();


	int sel = 0, cnt = 0;
	char choice;
	while (1) {
		cout << endl<< "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> sel >> cnt;
		if (sel == 1){ //��ũ��
			IP->printInkJet(cnt);
		}
		else { //������
			LP->printLaser(cnt);
		}
		IP->show(); LP->show();

		cout << "��� ����Ʈ �Ͻðڽ��ϴ�(y/n)>>"; cin >> choice;
		if (choice == 'y')
			continue;
		else
			break;
	}
	return 0;
}