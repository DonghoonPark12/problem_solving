#include "Ram.h"
#include <iostream>
#include <cstring>
using namespace std;
Ram::Ram() {
	memset(mem, 0, sizeof(mem));
	size = 0;
}


Ram::~Ram()
{
	cout << "�޸� ���ŵ�" << endl;
}

char Ram::read(int address)
{
	return mem[address];
}

void Ram::write(int address, char value)
{
	mem[address] = value;
}
