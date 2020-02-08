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
MyStack<T>::MyStack() //생성자??
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
* MyStack<int> iStack; 과 MyStack<double> dStack;을 만났을 경우
* 1. MyStack 템플릿의 T에 구체화된 버전의 Class 생성 ex)int, double형
* 2. 두 클래스를 컴파일 하고, iStack 객체와 dStack 객체를 생성하도록 컴파일
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