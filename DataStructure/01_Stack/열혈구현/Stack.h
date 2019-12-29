#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
private:
	int size;
	int top;
	T* stackPtr;
public:
	Stack(int = 10);
	Stack(Stack& s);

	bool push(const T&);
	bool pop(T&);

	bool isEmpty() const { return top == -1; }

	bool isFull() const { return top == size - 1; }

	~Stack() { delete[]stackPtr; }
};

#endif

template<typename T>
Stack<T>::Stack(int s)
	:size(s > 0 ? s : 10), top(-1), stackPtr(new T[size])
{ }

template<typename T>
Stack<T>::Stack(Stack& s)
	: size(s.size), top(s.top)
{
	stackPtr = new T[s.size];
	for (int i = 0; i <= s.top; i++) {
		stackPtr[i] = s.stackPtr[i];
	}
}

template<typename T>
bool Stack<T>::push(const T& pushvalue) {
	if (!isFull()) {
		stackPtr[++top] = pushvalue;
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::pop(T& popvalue) {
	if (!isEmpty()) {
		popvalue = stackPtr[top];
		stackPtr[top] = -1;
		top--;
		return true;
	}
	return false;
}

