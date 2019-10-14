//#include <cstdio>
#include <stdio.h>
#include "SimpleHeap_rev.h"

int main(){
    Heap heap;
    HeapInit(&heap);

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap)); 

    while(!HIsEmpty(&heap)){
        printf("%c \n", HDelete(&heap));
    }

    return 0;
}
