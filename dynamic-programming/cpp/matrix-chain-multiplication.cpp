// matrix chain multiplication

#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int matrix_chain_multi(int arr[], int i, int j)
{
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for(int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], matrix_chain_multi(arr, i, k) + matrix_chain_multi(arr, k+1, j) + arr[i-1] * arr[k] * arr[j]);
    }
    return dp[i][j];
}

int matrix_chain_order(int arr[], int n)
{
    int i = 1, j = n - 1;
    return matrix_chain_multi(arr, i, j);
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
    int k = matrix_chain_order(arr, n);
    cout << "Minimum number of multiplications : " << k;
    return 0;
}

