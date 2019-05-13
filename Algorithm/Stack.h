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