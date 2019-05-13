#include <iostream>
using namespace std;
class Book {
	char *title;
	int  price;
public:
	Book(char *title, int price);
	Book(Book &book);
	~Book();
	void set(char *title, int price);
	void show() { cout << title <<' ' << price << "¿ø" << endl; }

};