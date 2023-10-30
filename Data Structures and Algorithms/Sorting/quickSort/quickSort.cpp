#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;

    for(int j=l;j<r;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr,i,j);
        }
        
    }
    swap(arr,i+1,r);
    return i+1;
}

void quickSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int pi = partition(arr, l , r);

        quickSort(arr,l, pi-1);
        quickSort(arr,pi+1,r);
    }
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[10] = {5,8,1,36,12,32,6,21,9,0};
    int n = 10;

    printArray(arr,n);

    quickSort(arr,0,9);

    cout<<endl;

    printArray(arr,n);
}