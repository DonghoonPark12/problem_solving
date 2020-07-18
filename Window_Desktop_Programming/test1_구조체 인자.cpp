struct MyParam
{
    int size;
    int a, b, c;
};

struct MyParamEx
{
    int size;
    int a, b, c, d;
};

int Add(int a, int b)
{
    return a + b;
}

int Sum(MyParam* a_data)
{
    int (*p)(int a, int b);
    p = Add;
    p(2, 3);

    int result = 0;
    if (*(int*)a_data == sizeof(MyParam)) {

    }
    else {
        MyParamEx* p_ex = (MyParamEx*)a_data;
    }
    return result;
}

int main()
{
    MyParam data = { 5, 4, 1 };
    MyParamEx data_ex = { 5, 4, 1, 6 };

    int s = Sum((MyParam*)&data_ex);
    int s = Sum(a, b, c);
    int s = Sum(a, b, c);
    int s = Sum(a, b, c);
    int s = Sum(a, b);
    int s = Sum(a, b);
}


