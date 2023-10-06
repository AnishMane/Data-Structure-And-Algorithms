#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid -l +1;
    int n2 = r -mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++)
    {
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i] = arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(a[i] <b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else if(a[i] > b[j])
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}


void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
        int arr[10] = {8,3,9,2,65,32,78,21,33,1};
        int n = 10;

        printArray(arr,n);

        cout << endl;
        mergeSort(arr,0,9);

        printArray(arr,n);
}