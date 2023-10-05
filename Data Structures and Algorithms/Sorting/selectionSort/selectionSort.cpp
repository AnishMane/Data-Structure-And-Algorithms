#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
        for(int i=0;i<n-1;i++)
        {
            int min_index = i;
            for(int j=i+1; j<n;j++)
            {
                if(arr[min_index] > arr[j])
                {
                    min_index = j;
                }
            }
            swap(&arr[i], &arr[min_index]);
        }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n;i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
        int arr[7] = {9,17,25,2,34,8,1};
        int n=7;

        printArray(arr,n);

        cout << endl;

        selectionSort(arr,n);
        
        printArray(arr,n);
}