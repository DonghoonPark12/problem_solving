#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int *arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {};
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}
public:
	BoundCheckIntArray(int len)
		: arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[](int idx) const { //18�� �Լ��� �����ε� ����, ��¥�� ������ �Ұ��� �ϱ� ������ ���������� ��ȯ���� �ʴ´�. 
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() { delete[]arr; }
};

void ShowAllData(const BoundCheckIntArray& ref) {
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++) {
		cout << ref[idx] << endl; //int operator[](int idx) ȣ��
	}
}

typedef BoundCheckIntArray* BoundCheckIntPtr;
class BoundCheck2DIntArray {
private:
	BoundCheckIntArray **arr;
	int arrlen;
	BoundCheck2DIntArray(const BoundCheckIntArray& arr) {};
	BoundCheck2DIntArray& operator=(const BoundCheckIntArray& arr) {};
public:
	BoundCheck2DIntArray(int col, int row)
		: arrlen(col)
	{
		arr = new BoundCheckIntPtr[col];//Ŭ���� �������� �迭
		for (int i = 0; i < col; i++)
			arr[i] = new BoundCheckIntArray(row);//���ο� �ڷ�����  (row)�� ���ذ� �ȵȴ�->BoundCheckIntArrayŬ������ �ʱ� ���� �� �޴´�. 
	}
	BoundCheckIntArray& operator[](int idx) const { //18�� �Լ��� �����ε� ����, ��¥�� ������ �Ұ��� �ϱ� ������ ���������� ��ȯ���� �ʴ´�. 
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return *(arr[idx]);
	}
	~BoundCheck2DIntArray() {
		for (int i = 0; i < arrlen; i++) 
			delete arr[i];
		delete []arr;
	}
};

int main() {
	//BoundCheckIntArray arr(5);
	//for (int i = 0; i < 5; i++) {
	//	arr[i] = (i + 1) * 11; //int& operator[](int idx) ȣ��
	//}
	//ShowAllData(arr);

	BoundCheck2DIntArray arr2d(3, 4);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			arr2d[i][j] = i + j;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr2d[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}