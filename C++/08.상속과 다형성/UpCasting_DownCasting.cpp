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
	
	Point* pBase = pDev; //업 캐스팅, 부모 클래스 포인터가 자식 클래스 객체를 가리키는 것을 말한다.
						 //사람(pDev)은 동물(pBase)이다
						 //여기서 자식 객체를 가리킬 때 자식객체가 형변환을 할 필요 없다.
						 //(Point *)pDev에서 (Point *) 생략가능. 왜냐하면 '사람(pDev)은 동물(pBase)이다'
		
	pDev->set(3, 4);
	pBase->ShowPoint();
	pDev->setColor("Red");
	pDev->showColorPoint();
	//pBase->showColorPoint(); //하지만, 부모클래스 포인터가 '자식클래스에서만 생성된 멤버함수'를 호출할 순 없다.


	ColorPoint cp;
	ColorPoint* pDev;
	Point* pBase = &cp; //업 캐스팅, 

	pDev->set(3, 4);
	pBase->ShowPoint();
	pDev = (ColorPoint*)pBase; //다운 캐스팅, 부모 클래스 포인터로 자식 클래스 객체를 가리키고 있을 때.
	pDev->setColor("Red");
	pDev->showColorPoint();
	//pBase->showColorPoint(); //하지만, 부모클래스 포인터가 '자식클래스에서만 생성된 멤버함수'를 호출할 순 없다.

}