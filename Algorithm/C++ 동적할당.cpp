int *pInt = new int;
char *pChar = new char;
Circle *pCrcle = new Circle();//Circle Ŭ���� Ÿ���� ��ü �Ҵ�

int *pInt = new int(20); // �Ҵ�� ���ÿ� �ʱ�ȭ
char *pChar = new char('a'); 
Circle *pCrcle = new Circle();//Circle Ŭ���� Ÿ���� ��ü �Ҵ�

int *pInt = new int [5]; // �Ҵ�� ���ÿ� �ʱ�ȭ
delete[] pInt; //�迭 ��ȯ�� []�� �ʿ��ϴ�. 

// heap �޸𸮰� �����ϸ� NULL�� ���� �ϹǷ�
if (*pInt) {
	cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
	return 0;
}

delete pInt;
delete pChar;
delete pCircle;


//2���� �迭 ���� �Ҵ�
int sizeX = 5;
int sizeY = 10;

#include <string.h> //memset

int** arr = new int*[sizeY]; //��

for (int i = 0; i < sizeY; i++) {
	arr[i] = new int[sizeX];//��
	memset(arr[i], 0, sizeof(int) * sizeX);
}

for (int i = 0; i < sizeY; i++)
{
	delete[] arr[i];
}

delete[] arr;

