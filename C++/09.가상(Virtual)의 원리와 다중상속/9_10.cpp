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
	<Static ���>
	1) ��ü �����Ǹ� 0���� �ʱ�ȭ

	<Static ��� �Լ�>
	 1) A static member function can be called even if no objects of the class exist --> ��ü ���� ��� ȣ�� ����
	 2) and the static functions are accessed using only the class name and the scope resolution operator ::  --> (Ŭ���� �̸�)::(����ƽ ����Լ�)�� ����Ѵ�.
	 3) this �����ͷ� ���� �Ұ���

	 https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
*/
class UI {
public:
	static int menu() {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		int sel; cin >> sel;
		return sel;
	}
	static int select() {
		cout << "��:1, ��:2, �簢��:3 >> ";
		int shape; cin >> shape;
		return shape;
	}
	static int del() {
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
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
		cout << "�׷��� �������Դϴ�." << '\n';
		bool live = true;
		while (live) {
			switch (UI::menu()) { //static �Լ��� ��ü ���� ���ϰ� �ٷ� ȣ�� ����?
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