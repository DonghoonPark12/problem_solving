/* 명품 c++ 5.8문제 */
#define _CRT_SECURE_NO_WARNINGS

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
	void show() { cout << title << ' ' << price << "원" << endl; }

};

/*
* 에러가 안생기는데??? 디폴트 복사 생성자가 호출되도 문자열이 따로 분리된다.
*
*/
int main() {
	Book cpp("명품c++", 10000);
	Book java = cpp;//디폴트 복사 생성자가 호출되어서 문자열이 같은 공간을 할당할 것이라는 우려가 있었다.

	java.set("명품java", 12000);
	cpp.show();
	java.show();
}

Book::Book(char *title, int myprice)
	:price(myprice)
{
	this->title = new char[strlen(title) + 1];
	//p = mytitle;
	strcpy(this->title, title);
}

//컴파일러가 삽입하는 디폴트 복사 생성자
Book::Book(Book & book)
{
	this->title = book.title;
	this->price= book.price;
}
//문제에서 요구하는 답, 하지만 set 함수에서 이미 다른 공간에 문자열이 할당된다. 
//Book::Book(Book & book)
//{
//	this->title =new char[strlen(book.title) + 1];//여기서 cpp과 같은 공간에 할당되지 않는다.
//	strcpy(this->title, book.title);
//	this->price= book.price;
//}

void Book::set(char *title, int myprice)
{
	this->price = myprice;
	this->title =new char[strlen(title) + 1];//여기서 cpp과 같은 공간에 할당되지 않는다.
	//p = mytitle;
	strcpy(this->title, title);
}

Book::~Book()
{
	delete[]title;
}
//Book::Book(Book &book)