int *pInt = new int;
char *pChar = new char;
Circle *pCrcle = new Circle();//Circle 클래스 타입의 객체 할당

int *pInt = new int(20); // 할당과 동시에 초기화
char *pChar = new char('a'); 
Circle *pCrcle = new Circle();//Circle 클래스 타입의 객체 할당

int *pInt = new int [5]; // 할당과 동시에 초기화
delete[] pInt; //배열 반환은 []가 필요하다. 

// heap 메모리가 부족하면 NULL을 리턴 하므로
if (*pInt) {
	cout << "메모리를 할당할 수 없습니다.";
	return 0;
}

delete pInt;
delete pChar;
delete pCircle;


//2차원 배열 동적 할당
int sizeX = 5;
int sizeY = 10;

#include <string.h> //memset

int** arr = new int*[sizeY]; //행

for (int i = 0; i < sizeY; i++) {
	arr[i] = new int[sizeX];//열
	memset(arr[i], 0, sizeof(int) * sizeX);
}

for (int i = 0; i < sizeY; i++)
{
	delete[] arr[i];
}

delete[] arr;

