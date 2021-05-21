#include <bits/stdc++.h>

using namespace std;

int swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int bubbleSort(int arr[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j] , &arr[j+1]);
        }
    }
}

int main()
{
    int arr[] = {6, 3, 4, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
