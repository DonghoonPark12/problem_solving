#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	void set(int x, int y) {
		this->x = x; this->y = y;
	}
	void ShowPoint() {
		cout << "(" << x << "," << y << ")" << '\n';
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << " : ";
	ShowPoint();
}

int main() {
	ColorPoint cp;
	ColorPoint* pDev = &cp;
	
	Point* pBase = pDev; //�� ĳ����, �θ� Ŭ���� �����Ͱ� �ڽ� Ŭ���� ��ü�� ����Ű�� ���� ���Ѵ�.
						 //���(pDev)�� ����(pBase)�̴�
						 //���⼭ �ڽ� ��ü�� ����ų �� �ڽİ�ü�� ����ȯ�� �� �ʿ� ����.
						 //(Point *)pDev���� (Point *) ��������. �ֳ��ϸ� '���(pDev)�� ����(pBase)�̴�'
		
	pDev->set(3, 4);
	pBase->ShowPoint();
	pDev->setColor("Red");
	pDev->showColorPoint();
	//pBase->showColorPoint(); //������, �θ�Ŭ���� �����Ͱ� '�ڽ�Ŭ���������� ������ ����Լ�'�� ȣ���� �� ����.


	ColorPoint cp;
	ColorPoint* pDev;
	Point* pBase = &cp; //�� ĳ����, 

	pDev->set(3, 4);
	pBase->ShowPoint();
	pDev = (ColorPoint*)pBase; //�ٿ� ĳ����, �θ� Ŭ���� �����ͷ� �ڽ� Ŭ���� ��ü�� ����Ű�� ���� ��.
	pDev->setColor("Red");
	pDev->showColorPoint();
	//pBase->showColorPoint(); //������, �θ�Ŭ���� �����Ͱ� '�ڽ�Ŭ���������� ������ ����Լ�'�� ȣ���� �� ����.

}