// Quick Sort

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int partition(int arr[], int low, int high)
    {
       int pivot = arr[high];
       int i = low-1;
       for(int j = low; j < high; j++)
       {
           if(arr[j] < pivot)
           {
               i++;
               swap(&arr[j], &arr[i]);
           }
       }
       swap(&arr[i+1], &arr[high]);
       return (i+1);
    }

public:
    void quickSort(int arr[], int low, int high)
    {
        if(low < high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p -1);
            quickSort(arr, p+1, high);
        }
    }
};

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, k;
    cout << "Enter number of array elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = s;
    }

    cout << "Original Array: ";
    printArray(arr, n);

    Solution ob;
    ob.quickSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
