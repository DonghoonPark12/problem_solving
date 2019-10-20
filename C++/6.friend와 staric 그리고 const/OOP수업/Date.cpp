// Date class�� ����Լ� ����.
#include "Date.h"

// ������ ����
Date::Date(int mn, int dy, int yr)
{
	// ���� �Է��� ���� 1~12��� �״��
	// �ƴ϶�� 1�� private ���� month�� ����
	if (mn > 0 && mn <= 12)
		month = mn;
	else {
		month = 1;
		cout << "Invalid month (" << mn << ") set to 1.\n";
	}

	// �⵵�� input��� private ���� year�� ����
	year = yr;

	// ���� check�ϴ� �Լ��� ���� private ���� day�� ����
	day = checkDay(dy);

	// Date object�� ���� Ȯ��
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

// ��/��/�� format�� ��¥ ��� �Լ� ����
void Date::print() const
{
	cout << month << '/' << day << '/' << year;
} 

// �Ҹ��� ����
Date::~Date()
{
	// Date object�� �Ҹ� Ȯ��
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

// �Է��� �⵵�� ���� �´� ������ Ȯ���ϴ� �Լ� ����
int Date::checkDay(int testDay) const
{
	// �迭�� �̿��� �� ���� ������ ���� ����
	// ex) 1���� 31�� ��������, 2���� ������ �ƴ� ���� 28�� base��
	static const int daysPerMonth[13] = 
	{ 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };

	// ��� ���� �ش��ϴ� ������ ��ȿ�� �˻�
	if ((testDay > 0) && (testDay <= daysPerMonth[month]))
		return testDay;

	// ������ check -> 2�� 29�� check
	// ���� �Է����� 2�� 29���� �޾��� ��
	// 4�� ���� �������� �ش� ����
	// �� �߿��� 100���� ���� �������� �ش� ���(���� x)
	// ������ 400���� �� ���� �������� �ش� ����
	if ((month == 2) && (testDay == 29) && 
		(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		// ���ǿ� ������ input�� �Ϸ�
		return testDay;

	// ���ǿ� ���� �ʴ´ٸ� 1�� �Ϸ�
	cout << "Invalid day (" << testDay << ") set to 1.\n";

	return 1;
}
