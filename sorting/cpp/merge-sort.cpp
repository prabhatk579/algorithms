// Merge Sort

#include <bits/stdc++.h>

using namespace std;

class Solution
{
     void merge(int arr[], int left, int mid, int right)
     {
         int llen = mid - left + 1;
         int rlen = right - mid;

         int L[llen], R[rlen];

         for(int i = 0; i < llen; i++)
             L[i] = arr[left+i];

         for(int j = 0; j < rlen; j++)
             R[j] = arr[mid+1+j];

         int i = 0, j = 0, k = left;

         while(i < llen && j < rlen)
         {
             if(L[i] <= R[j])
             {
                 arr[k] = L[i];
                 k++;
                 i++;
             }
             else
             {
                 arr[k] = R[j];
                 k++;
                 j++;
             }
         }

         while(i < llen)
         {
            arr[k] = L[i];
            i++;
            k++;
         }

         while(j < rlen)
         {
            arr[k] = R[j];
            j++;
            k++;
         }
     }

public:

    void mergeSort(int arr[], int left, int right)
    {
        if (left < right)
        {
           int mid = left + (right - left)/2;

           mergeSort(arr, left, mid);
           mergeSort(arr, mid + 1, right);

           merge(arr, left, mid, right);
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
    ob.mergeSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
