#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j>0;j--)
        {
            if(arr[j] < arr[j-1])
            {
                swap(&arr[j], &arr[j-1]);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {7,3,8,2,9,1};
    int n = 6;

    printArray(arr,n);
    cout << endl;
    insertionSort(arr,n);

    printArray(arr,n);
}