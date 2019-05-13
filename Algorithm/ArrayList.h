//#ifndef __ARRAY_LIST_H__
//#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100
//#include <../C,C++/Data_Structure_Src/Ch03/ArrayListPointStructBase/Point.h>
#include <../C,C++/NameCard2.h>

//typedef int LData;
//typedef Point *LData; //int --> Point*
typedef NameCard *LData; 

typedef struct __ArrayList
{
	LData arr[LIST_LEN]; //NameCard 구조체 배열을 원소로 가지는 배열기반 리스트.
	int numOfData;
	int curPosition; //데이터 참조 위치 기록
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List *plist, int(*comp)(LData d1, LData d2));
//#endif