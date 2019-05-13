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
			top = 0; bottom = 0;//환형 큐가 아니므로, 큐가 비었을 떄는 원점으로 돌려 놓는다.
			return -1;//비었을 때는 하단 코드가 동작하면 안된다. 
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
	//cout<<"큐에 삽입할 5개의 정수를 입력하라>> ";
	//for (int i = 0; i < 5; i++) {
	//	cin >> n;
	//	mQ.enqueue(n);
	//}
	//cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	//while(mQ.length() != 0) {
	//	cout << mQ.dequeue() << ' ';
	//}
	//cout << endl << "큐의 현재 크기 :" << mQ.length() << endl;

	MyStack mS(100);
	int n;
	cout<<"스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mS.push(n);
	}
	cout << "스택의 용량:" << mS.capacity() << ", 스택의 크기:" << mS.length() << endl;
	while(mS.length() != 0) {
		cout << mS.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 :" << mS.length() << endl;
}
