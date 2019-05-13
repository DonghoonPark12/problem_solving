#include <iostream>
using namespace std;

template <class T>
class MyStack {
	int tos;
	T data[100];
public:
	MyStack();
	void push(T element);
	T pop();
};

template <class T>
MyStack<T>::MyStack() //������??
{
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element)
{
	if (tos == 99) {
		cout << "Stack is full";
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop()
{
	if (tos == -1) {
		cout << "Stack is empty";
		return;
	}
	tmp = data[tos]
	tos--;
	return tmp; //tmp = data[tos--]; 
}

/* 
* MyStack<int> iStack; �� MyStack<double> dStack;�� ������ ���
* 1. MyStack ���ø��� T�� ��üȭ�� ������ Class ���� ex)int, double��
* 2. �� Ŭ������ ������ �ϰ�, iStack ��ü�� dStack ��ü�� �����ϵ��� ������
*/

MyStack<char> *p = new MyStack<char>();

int main()
{
	MyStack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<char> *p = new MyStack<char>();
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}