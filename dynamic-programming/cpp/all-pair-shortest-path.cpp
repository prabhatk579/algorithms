// All Pair Shortest Path

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int A[n][n];

    cout << endl << "Enter values of vertices in graph: " << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << endl << "Print graph in matrix form: " << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] <= 0 && i != j)
                A[i][j] = -1;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    A[i][j] = 0;
                else
                {
                    int a = A[i][j];
                    int b = A[i][k];
                    int c = A[k][j];

                    if(b == -1 || c == -1)
                        continue;
                    else
                    {
                        b = b + c;
                        if(a > b)
                            A[i][j] = b;
                    }
                }
            }
        }
    }

    cout << endl << "Shortest Distance" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

