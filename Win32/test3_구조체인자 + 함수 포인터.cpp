#define CALLBACK __stdcall
#define WINAPI __stdcall 

/*
//�ü�� ���� �Լ�
void CALLBACK ModifyData(int* p)    //__cdecl
{
    if (*p < 0) *p *= -1;
}
*/

void ModifyData(int* p)    //__cdecl
{
    if (*p < 0) *p *= -1;
}

void ModifyData2(int* p)
{
    if (*p < 0) *p = 0;
}

struct MyData
{
    int a;
    int b;
    void (*ap_modify)(int* p);
};

int Sum(MyData* ap_data)
{
    ap_data->ap_modify(&ap_data->a);  // (*ap_modify)(&a);
    return ap_data->a + ap_data->a;
}

int main()
{
    /* ����� ���� */
    MyData data;
    data.a = 5;
    data.b = -2;
    data.ap_modify = ModifyData;
    int s = Sum(&data);

    return 0;
}
