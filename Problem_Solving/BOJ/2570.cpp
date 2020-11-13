#include <iostream>
using namespace std;
int num;
int arr[1000];

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << '\n';
}

// Driver program to test above functions  
int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    bubbleSort(arr, num);
    printArray(arr, num);
    return 0;
}