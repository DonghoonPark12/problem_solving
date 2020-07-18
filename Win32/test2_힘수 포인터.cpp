void ModifyData(int* p)
{
    if (*p < 0) *p *= -1;
}

void ModifyData2(int* p)
{
    if (*p < 0) *p = 0;
}

int Sum(int a, int b, void (*ap_modify)(int* p))
{
    ap_modify(&a);  // (*ap_modify)(&a);
    return a + b;
}

int main()
{
    int s = Sum(3, 5, ModifyData);
    int s = Sum(3, 5, ModifyData2);

    return 0;
}
