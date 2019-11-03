class MyIntStack{
	int *p;
	//int p[10];
	int top;
	int size;
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack &s);
	~MyIntStack();
	bool push(int n);
	bool pop(int &n);
 };

MyIntStack::MyIntStack()
	:top(0)
{ }

MyIntStack::MyIntStack(int mysize)
	: size(mysize), top(0)
{
	p = new int[size];//길이가 size인 배열의 할당
}

/* 클래스 생성 */
MyIntStack::MyIntStack(MyIntStack &s)//깊은 복사
	: size(s.size), top(s.top)
{
	/*
	* this는 객체 자기자신을 가리키는 포인터다.
	* 여기 문제에서는 this를 써도되고 안써도 된다.
	* b객체의 내부변수를 가리키기 때문이다.
	*/
	//this->size = s.size; this->top = s.top;
	//this->p = new int[s.size];
	p = new int[s.size];
	for (int i = 0; i < s.top; i++) {
		//this->p[i] = s.p[i];
		p[i] = s.p[i];
	}
}

MyIntStack::~MyIntStack()
{
	delete[]p;
}

bool MyIntStack::push(int n)
{
	if (top == 10) {
		return false;
	}
	else {
		p[top++] = n;
		return true;
	}
}

bool MyIntStack::pop(int &n)
{
	if (top == 0) {
		return false;
	}
	else {
		top--;
		n = p[top];
		p[top] = -1;
		return true;
	}
}