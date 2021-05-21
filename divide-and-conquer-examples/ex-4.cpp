/* Given an array of n elements, give an algorithm for checking whether there are any
 * duplicate elements in the array or not? in O(nlogn) time.
 */


#include <bits/stdc++.h>

using namespace std;

int findDuplicate(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        if(arr[i-1] == arr[i])
            return 1;
    }
    return 0;
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
    sort(arr, arr + n);
    k = findDuplicate(arr, n);

    if(k == 0)
        cout << "No Duplicates Present!";
    else
        cout << "Duplicates Present!";

    return 0;
}
