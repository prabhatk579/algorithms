/*  Let A and B be two arrays of n elements. Given a number K, draw an O(nlogn) time
 * algorithm for determining whether there exists a ∈ A, b ∈ B such that a+b = K or not?.
 */


#include <bits/stdc++.h>

using namespace std;

int findSum(int A[], int B[], int n, int k)
{
    for(int i = 0; i < n; i++)
    {
        //int low = A[0], high = A[n-1];
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (high + low)/2;
            if(B[mid] == k-A[i])
                return 1;
            else if(B[mid] < k-A[i])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return 0;
}

int main()
{
    int n, k;

    cout << "Enter number of elements of arrays: ";
    cin >> n;

    int A[n];
    int B[n];

    cout << "Enter element (whose sum to be found): ";
    cin >> k;

    cout << "Enter array 1 elements:";
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        A[i] = p;
    }

    cout << "Enter array 2 elements:";
    for(int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        B[i] = q;
    }

    cout << "Print Array 1:" << " ";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "Print Array 2:" << " ";
    for(int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << endl;

    sort(A, A + n);
    sort(B, B + n);

    int kk = findSum(A, B, n, k);

    if(kk == 1)
        cout << "Positive Result!" << endl;
    else
        cout << "Negative Result!" << endl;

    return 0;
}
