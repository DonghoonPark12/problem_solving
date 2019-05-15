#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; 
		mem = new int[capacity];
	}
	~BaseArray() { delete[]mem; }
	void put(int index, int val) {
		mem[index] = val;
	}
	int get(int index) {
		return mem[index];
	}
	int getCapacity() {
		return capacity;
	}
};
class MyStack :BaseArray {
	int top;
public:
	MyStack(int cap)
		:top(0), BaseArray(cap)
	{}
	void push(int n) {
		if (top == 100) cout << "Stack is full~!" << endl;
		put(top++, n);
	}
	int pop() {
		if (top == 0) cout << "Stack is empty~!" << endl;
		top--;
		return get(top);
	}
	int capacity() { return getCapacity(); }
	int length() { return top; }
};

class MyQueue : BaseArray {
	int bottom;
	int top;
public:
	MyQueue(int cap)
		:BaseArray(cap), top(0), bottom(-1)
	{}
	void enqueue(int n) {
		if (top == 99)
			if (bottom == -1) {
				cout << "Qeueu is full~!" << endl; return;
			}
			else
				top -= 99;
		else if (bottom - top == 1) {
			cout << "Qeueu is full~!" << endl; return;
		}
		put(top, n);
		top++;
	}
	int dequeue() {
		if (bottom == top) {
			cout << "Qeueu is empty~!" << endl;
			top = 0; bottom = 0;//ȯ�� ť�� �ƴϹǷ�, ť�� ����� ���� �������� ���� ���´�.
			return -1;//����� ���� �ϴ� �ڵ尡 �����ϸ� �ȵȴ�. 
		}
		if (bottom == 99) bottom -= 99;

		bottom++;
		int tmp = get(bottom);
		put(bottom, -1);
		return tmp;
	}
	int capacity() { return getCapacity(); }
	int length() { return top-bottom -1; }
};

int main() {
	//MyQueue mQ(100);
	//int n;
	//cout<<"ť�� ������ 5���� ������ �Է��϶�>> ";
	//for (int i = 0; i < 5; i++) {
	//	cin >> n;
	//	mQ.enqueue(n);
	//}
	//cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	//while(mQ.length() != 0) {
	//	cout << mQ.dequeue() << ' ';
	//}
	//cout << endl << "ť�� ���� ũ�� :" << mQ.length() << endl;

	MyStack mS(100);
	int n;
	cout<<"���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mS.push(n);
	}
	cout << "������ �뷮:" << mS.capacity() << ", ������ ũ��:" << mS.length() << endl;
	while(mS.length() != 0) {
		cout << mS.pop() << ' ';
	}
	cout << endl << "������ ���� ũ�� :" << mS.length() << endl;
}
