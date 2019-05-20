#include <iostream>
#include "Rectangle.h"
using namespace std;
Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
	:upleft(x1, y1), lowRight(x2, y2)
{

}

void Rectangle::ShowRecInfo() const{
	cout << "�� ���: " << "[" << upleft.GetX() << ", ";
	cout << upleft.GetY() << ']' << endl;
	cout << "�� �ϴ�: " << "[" << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl;
}
