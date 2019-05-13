//#ifndef __ARRAY_LIST_H__
//#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList�� ���� ****/
#define LIST_LEN	100
//#include <../C,C++/Data_Structure_Src/Ch03/ArrayListPointStructBase/Point.h>
#include <../C,C++/NameCard2.h>

//typedef int LData;
//typedef Point *LData; //int --> Point*
typedef NameCard *LData; 

typedef struct __ArrayList
{
	LData arr[LIST_LEN]; //NameCard ����ü �迭�� ���ҷ� ������ �迭��� ����Ʈ.
	int numOfData;
	int curPosition; //������ ���� ��ġ ���
} ArrayList;


/*** ArrayList�� ���õ� ����� ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List *plist, int(*comp)(LData d1, LData d2));
//#endif