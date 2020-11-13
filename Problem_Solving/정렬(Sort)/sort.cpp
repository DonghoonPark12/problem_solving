#include <iostream>
using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//선택 정렬,  오름 차순 정렬
//작은 값을 찾아서 앞에 놓기
//ex) 선생님이 학생들 키 작은 순서로 줄을 세울 때, 학생들 스캔하는 방법.
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) //→
    {
        //최소값 인덱스를 일단 i로 둔다.  
        min_idx = i; 
        for (j = i + 1; j < n; j++) { //→
            //최소값 인덱스(min_idx)를 기억해 둔다
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }

        // 최소값을 i위치에 둔다.
        swap(&arr[min_idx], &arr[i]);
    }
}

//버블 정렬
//ex) 정육사가 줄세울 때, 큰소를 맨뒤로 보내기 위해서 버블 정렬한다.
//    맨 뒤는 가장 큰 소가 오므로 다음 부턴 검사할 필요 없다.
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--) //←
    {
        for (int j = 0; j < i; j++) //→
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}


//삽입 정렬
// ex) 학생들이 한줄로 서있을 때, 키 작은 학생이 앞으로 가는 원리
//     2번 부터 ~ 마지막 학생들까지 앞으로 갈때, 바로 앞의 학생과 비교.
void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) //→
    {
        for (int j = i; j > 0; j--) //←
        {
            if(arr[j-1] > arr[j])
                swap(&arr[j], &arr[j - 1]);
        }
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; //left
    int r = 2 * i + 2; //right

    // If left index is smaller than heap size && left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    //힙 생성
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i); // Creates a max heap

    //하나하나 힙에서 요소 제거
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Swaps first and last node(가장 큰 노드가 배열의 뒷쪽으로 간다. Max Heap --> 오름차순 정렬)
        heapify(arr, i, 0);   // Creates max heap on reduced array
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions  
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}