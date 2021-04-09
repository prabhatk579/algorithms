// matrix chain multiplication

#include <bits/stdc++.h>

using namespace std;

int minMatMul(int arr[], int i, int j)
{
    if(i == j)
        return 0;
    int min = INT_MAX;
    int count;
    for(int k = i; k < j; k++)
    {
        count = minMatMul(arr, i, k) + minMatMul(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        if(count < min)
            min = count;
    }
    return min;
}

int main()
{
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[n];

    cout << "Enter Elements: ";
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = s;
    }
    int k = minMatMul(arr, 1, n-1);
    cout << "Minimum number of multiplications : " << k;
    return 0;
}
