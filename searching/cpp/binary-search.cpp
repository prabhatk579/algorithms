// Binary Search

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int iterativeBinarySearch(int arr[], int low, int high, int k)
    {
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == k)
                return mid;
            else if(arr[mid] > k)
                high = mid -1;
            else
                low = mid +1;
        }
    }
    int recursiveBinarySearch(int arr[], int low, int high, int k)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid] > k)
            recursiveBinarySearch(arr, low, mid-1, k);
        else
            recursiveBinarySearch(arr, mid+1, high, k);
    }
};

int main()
{
    int n, k;
    cout << "Enter number of array elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter digit to be found: ";
    cin >> k;
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = s;
    }
    sort(arr, arr + n);
    int low = 0;
    int high = n-1;
    Solution ob;
    int a = -1, b = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == k)
        {
            cout << "Digit Found! Go for Binary Search to find position." << endl;
            a = ob.iterativeBinarySearch(arr, low, high, k);
            b = ob.recursiveBinarySearch(arr, low, high, k);
            break;
        }
    }
    if(a == -1 && b == -1)
    {
        cout << "Element Not Present";
    }
    else
    {
        cout << "Element Position (Iterative Search): " << a << endl;
        cout << "Element Position (Recursive Search): " << b << endl;
    }
    return 0;
}
