/* Given an array of n elements, give an algorithm for finding the element which appears
 * maximum number of times in the array in O(nlogn) time.
 */


#include <bits/stdc++.h>

using namespace std;

int maxAppear(int arr[], int n)
{
    sort(arr, arr + n);
    int countEle = 1, maxCount = 1, freq = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i-1] == arr[i])
            countEle++;
        else
        {
            if(countEle > maxCount)
            {
                maxCount = countEle;
                freq = arr[i-1];
            }
            countEle = 1;
        }
    }
    if(countEle > maxCount)
    {
        maxCount = countEle;
        freq = arr[n-1];
    }
    return freq;
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

    k = maxAppear(arr, n);

    cout << k << " appears maximum!";

    return 0;
}

