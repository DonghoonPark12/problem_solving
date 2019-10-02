#ifndef ACCOUNT_ARRAY_H
#define ACCOUNT_ARRAY_H
#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckPointArr {
private:
	ACCOUNT_PTR *arr;
	int arrlen;
	BoundCheckPointArr(const BoundCheckPointArr &arr) {}
	BoundCheckPointArr& operator=(const BoundCheckPointArr& arr) {}

public:
	BoundCheckPointArr(int arrlen = 100);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckPointArr();
};
#endif // !1


