// linear search

#include <bits/stdc++.h>

using namespace std;

int linearSearch(int arr[], int size, int k)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout << "Enter element to search : ";
    cin >> k;
    int result = linearSearch(arr, size, k);
    if(result == -1)
    {
        cout << "Element not present.";
    }
    else
    {
        cout << "Element is present and at position " << result;
    }
    return 0;
}
