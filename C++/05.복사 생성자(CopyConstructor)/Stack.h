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
	p = new int[size];//���̰� size�� �迭�� �Ҵ�
}

/* Ŭ���� ���� */
MyIntStack::MyIntStack(MyIntStack &s)//���� ����
	: size(s.size), top(s.top)
{
	/*
	* this�� ��ü �ڱ��ڽ��� ����Ű�� �����ʹ�.
	* ���� ���������� this�� �ᵵ�ǰ� �Ƚᵵ �ȴ�.
	* b��ü�� ���κ����� ����Ű�� �����̴�.
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