#include <bits/stdc++.h>

using namespace std;

/*int swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}*/

int recursiveBubble(int arr[], int n)
{
    if(n == 1)
        return arr[0];
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    recursiveBubble(arr, n-1);
}

int main()
{
    int arr[] = {7, 5, 6, 2, 9, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    recursiveBubble(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
