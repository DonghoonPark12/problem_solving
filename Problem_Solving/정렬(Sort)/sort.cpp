#include <iostream>
using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//���� ����,  ���� ���� ����
//���� ���� ã�Ƽ� �տ� ����
//ex) �������� �л��� Ű ���� ������ ���� ���� ��, �л��� ��ĵ�ϴ� ���.
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) //��
    {
        //�ּҰ� �ε����� �ϴ� i�� �д�.  
        min_idx = i; 
        for (j = i + 1; j < n; j++) { //��
            //�ּҰ� �ε���(min_idx)�� ����� �д�
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }

        // �ּҰ��� i��ġ�� �д�.
        swap(&arr[min_idx], &arr[i]);
    }
}

//���� ����
//ex) �����簡 �ټ��� ��, ū�Ҹ� �ǵڷ� ������ ���ؼ� ���� �����Ѵ�.
//    �� �ڴ� ���� ū �Ұ� ���Ƿ� ���� ���� �˻��� �ʿ� ����.
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--) //��
    {
        for (int j = 0; j < i; j++) //��
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}


//���� ����
// ex) �л����� ���ٷ� ������ ��, Ű ���� �л��� ������ ���� ����
//     2�� ���� ~ ������ �л������ ������ ����, �ٷ� ���� �л��� ��.
void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) //��
    {
        for (int j = i; j > 0; j--) //��
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
    //�� ����
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i); // Creates a max heap

    //�ϳ��ϳ� ������ ��� ����
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Swaps first and last node(���� ū ��尡 �迭�� �������� ����. Max Heap --> �������� ����)
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