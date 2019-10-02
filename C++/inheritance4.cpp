#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BookClass.h"
using namespace std;

class Book {
private:
	char *title;
	char *isbn;
	int price;
public:
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	Book(char *ti, char *is, int pr)
		:price(pr)
	{
		title = new char[strlen(ti) + 1];
		strcpy(title, ti);
		isbn = new char[strlen(is) + 1];
		strcpy(isbn, is);
	}
	//깊은 복사 생성자
	Book(const Book &copy)
		:price(copy.price)
	{
		title = new char[strlen(copy.title) + 1];
		strcpy(title, copy.title);
		isbn = new char[strlen(copy.isbn) + 1];
		strcpy(isbn, copy.isbn);
	}
	
	//대입 연산자
	Book& operator=() {

		return *this
	}

	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char *DRMKey;
public:
	void ShowEbookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	EBook(char *ti, char *is, int pr, char *DR)
		: Book(ti, is, pr)
	{
		DRMKey = new char[strlen(DR) + 1];
		strcpy(DRMKey, DR);
	}
	//대입연산자

	//깊은 복사 생성자
	~EBook()
	{
		delete[] DRMKey;
	}
};

int main() {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdwjfh823");
	ebook.ShowEbookInfo();
	return 0;
}