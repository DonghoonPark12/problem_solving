#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape {
public:
	string name = "masaka";
	virtual string getName() = 0;
};

class Line : public Shape {
public:
	string name = "Line";
	int len;
	string getName() { return name; }
};

class Circle : public Shape {
public:
	string name = "Circle";
	int Area;
	int radius;
	string getName() { return name; }
};

class Rect : public Shape {
public:
	string name = "Rect";
	int Area;
	int l;
	string getName() { return name; }
};

/*
	<Static 멤버>
	1) 객체 생성되면 0으로 초기화

	<Static 멤버 함수>
	 1) A static member function can be called even if no objects of the class exist --> 객체 생성 없어도 호출 가능
	 2) and the static functions are accessed using only the class name and the scope resolution operator ::  --> (클래스 이름)::(스테틱 멤버함수)로 사용한다.
	 3) this 포인터로 접근 불가능

	 https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
*/
class UI {
public:
	static int menu() {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		int sel; cin >> sel;
		return sel;
	}
	static int select() {
		cout << "선:1, 원:2, 사각형:3 >> ";
		int shape; cin >> shape;
		return shape;
	}
	static int del() {
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		int idx; cin >> idx;
		return idx;
	}
};

class GraphicEditor {
private:
	//Shape* pStart, * pLast;
	int cnt;
	vector<Shape*> v;
	vector<Shape*>::iterator iter;
public:
	void _push(int shape) {
		if (shape == 1) {
			Line* l = new Line(); v.push_back(l); cnt++;
		}
		else if (shape == 2) {
			Circle* c = new Circle(); v.push_back(c); cnt++;
		}
		else if (shape == 3) {
			Rect* r = new Rect(); v.push_back(r);cnt++;
		}
		else {
			cout << "Wrong Shape!!" << '\n';
		}
	}
	void _del(int idx) {
		iter = v.begin() + idx; v.erase(iter);
	}
	void _show() {
		int i = 0;
		for (iter = v.begin(); iter != v.end(); ++iter)
			cout << i++ << ": " << (*iter)->getName() << '\n';
	}

	void call() {
		cout << "그래픽 에디터입니다." << '\n';
		bool live = true;
		while (live) {
			switch (UI::menu()) { //static 함수는 객체 생성 안하고 바로 호출 가능?
			case 1:
				_push(UI::select());
				break;
			case 2:
				_del(UI::del());
				break;
			case 3:
				_show();
				break;
			case 4:
				live = false;
				break;
			}
		}
		return;
	}
};

int main() {
	GraphicEditor* ge = new GraphicEditor();
	ge->call();
	delete ge;
	return 0;
}