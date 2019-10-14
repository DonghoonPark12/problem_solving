#include "SimpleHeap_rev.h"

void HeapInit(Heap *ph, PriorityComp pc){
    ph->numOfData = 0;
    ph->cmp = pc;
}

int HIsEmpty(Heap * ph){
    if(ph->numOfData == 0)
        return True;
    else
        return False;
}

int GetParentIDX(int idx){
    return idx/2;
}

int GetLChildIDX(int idx){
    return idx*2;
}

int GetRChildIDX(int idx){
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx){ //Heap 삭제 함수에서 쓰인다. 
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if(GetLChildIDX(idx)== ph->numOfData){
        return GetLChildIDX(idx);
    }
    else{
        //if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
        if(ph->cmp(  ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]  ) < 0)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

HData HDelete(Heap * ph){
    //HData retData = (ph->heapArr[1]).data;
    //HeapElem lastElem = ph->heapArr[ph->numOfData];
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1; 
    int childIdx;

    while(childIdx = GetHiPriChildIDX(ph, parentIdx)){
        //if(lastElem.pr <= ph->heapArr[childIdx].pr) //자식 노드의 숫자 값이 lastElem의 숫자 값 보다 크다면, 제자리를 찾았음
        if(ph->cmp(lastElem, ph->heapArr[childIdx]) > 0)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx]; //(최소힙 기준) 자식 노드의 값이 부모 노드 보다 값이 작다면
        parentIdx = childIdx;
    }
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -=1;
    return retData;
}

//void HInsert(Heap *ph, HData data, Priority pr){
void HInsert(Heap *ph, HData data){
    int idx = ph->numOfData + 1;
    //HeapElem nelem = {pr, data}; //새 노드의 생성 및 초기화

    while(idx != 1){ //새 노드가 저장될 위치가 루트 노드가 아니라면 while문 반복
        //if(pr < (ph->heapArr[GetParentIDX(idx)].pr)){ //(최소힙 기준) 새노드의 값(우선순위)가 더 작다면 : 올라가야 된다.
        if(ph->cmp(data, ph->heapArr[GetParentIDX(idx)]) > 0){
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; //실제로 내림
            idx = GetParentIDX(idx); //idx를 부모의 위치 것으로 갱신
        }
        else // (최소힙 기준) 부모 노드의 값이 더 작다면, 제자리를 찾았음. 
            break;
    }
    //ph->heapArr[idx] = nelem;
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}