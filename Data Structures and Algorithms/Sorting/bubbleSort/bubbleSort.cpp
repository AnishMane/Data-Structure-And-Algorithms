#include <iostream>

using namespace std;

void swap(int*a,int*b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for(int i =0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Total Numbers in the array: ";
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout << "Number for Index "<< i << " : " << endl;
        cin >> arr[i];
    }
    printArray(arr,n);
    cout << endl;
    bubbleSort(arr,n);
    printArray(arr,n);
}