#include <iostream>
#include "AccountArray.h"
using namespace std;

BoundCheckPointArr::BoundCheckPointArr(int len)
	:arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR & BoundCheckPointArr::operator[](int idx) {
	if (idx<0 || idx >> arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BoundCheckPointArr::operator[](int idx) const {
	if (idx<0 || idx >> arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return ACCOUNT_PTR();
}

int BoundCheckPointArr::GetArrLen() const {
	return arrlen;
}

BoundCheckPointArr::~BoundCheckPointArr() {
	delete[]arr;
}
