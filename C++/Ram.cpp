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
	cout << "메모리 제거됨" << endl;
}

char Ram::read(int address)
{
	return mem[address];
}

void Ram::write(int address, char value)
{
	mem[address] = value;
}
