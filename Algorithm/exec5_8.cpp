#define _CRT_SECURE_NO_WARNINGS
#include "BookClass.h"
/*
* ������ �Ȼ���µ�??? ����Ʈ ���� �����ڰ� ȣ��ǵ� ���ڿ��� ���� �и��ȴ�.
*
*/
int main() {
	Book cpp("��ǰc++", 10000);
	Book java = cpp;//����Ʈ ���� �����ڰ� ȣ��Ǿ ���ڿ��� ���� ������ �Ҵ��� ���̶�� ����� �־���.

	java.set("��ǰ java", 12000);
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

//�����Ϸ��� �����ϴ� ����Ʈ ���� ������
Book::Book(Book & book)
{
	this->title = book.title;
	this->price= book.price;
}
//�������� �䱸�ϴ� ��, ������ set �Լ����� �̹� �ٸ� ������ ���ڿ��� �Ҵ�ȴ�. 
//Book::Book(Book & book)
//{
//	this->title =new char[strlen(book.title) + 1];//���⼭ cpp�� ���� ������ �Ҵ���� �ʴ´�.
//	strcpy(this->title, book.title);
//	this->price= book.price;
//}

void Book::set(char *title, int myprice)
{
	this->price = myprice;
	this->title =new char[strlen(title) + 1];//���⼭ cpp�� ���� ������ �Ҵ���� �ʴ´�.
	//p = mytitle;
	strcpy(this->title, title);
}

Book::~Book()
{
	delete[]title;
}
//Book::Book(Book &book)