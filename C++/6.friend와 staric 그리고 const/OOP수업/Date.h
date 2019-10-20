// ��¥(Date) class ���� �G ����
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <time.h>   
using namespace std;

class Date
{
public:
	Date(int = 1, int = 1, int = 1900); // ��/��/�� format�� ������
	void print() const; // ��/��/�� format�� ��¥ ��� �Լ�
	~Date(); // �Ҹ��� ����
private:
	int month; // 1������ 12��
	int day; // 1�Ϻ��� 31��
	int year; // �⵵
	
	// �Է��� �⵵�� ���� �´� ������ Ȯ���ϴ� �Լ�
	int checkDay(int) const; 

	void printDDDYYYY() const;
	void printMMDDYY() const;
	void printMonthDDYYYY() const;

	int daysInMonth(int) const;
	bool isLeapYear();
}; 

//Date::Date(int, int, int) {
//
//}

#endif
