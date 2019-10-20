#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define True 1
#define False 0

#define HEAP_LEN 100

typedef char HData;
//typedef int Priority;
typedef int PriorityComp(HData d1, HData d2);

// typedef struct __heapElem{
//     Priority pr;
//     HData data;
// } HeapElem;

// typedef struct _heap{
//     int numOfData;
//     HeapElem heapArr[HEAP_LEN];
// } Heap;

typedef struct _heap{
    PriorityComp *cmp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);

int HIsEmpty(Heap *ph);

//void HInsert(Heap * ph, HData data, Priority pr);
void HInsert(Heap * ph, HData data);

HData HDelete(Heap *ph);

#endif