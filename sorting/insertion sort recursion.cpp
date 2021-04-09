#include <bits/stdc++.h>

using namespace std;

int recursiveInsertion(int arr[], int n)
{
    if(n <= 1)
        return arr[0];
    recursiveInsertion(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while(j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    recursiveInsertion(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
