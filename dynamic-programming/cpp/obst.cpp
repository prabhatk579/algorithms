// construction of OBST

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of internal nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter nodes of tree: " << endl;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    cout << "Print nodes of tree: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    float p[n+1];
    float q[n+1];
    float weight[n+1][n+1];
    float cost[n+1][n+1];

    cout << "Enter successful search probabilities: ";
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        p[i] = k;
    }

    cout << "Enter unsuccessful search probabilities: ";
    for(int i = 0; i <= n; i++)
    {
        int k;
        cin >> k;
        q[i] = k;
    }

    for(int i = 0; i <= n ; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(i == j)
                weight[i][j] = 0;
            else
                weight[i][j] = p[i] + q[i] + weight[i][j-1];
        }
    }

    for(int k = 1; k <= n; k++)            // level length
    {
        for(int i = 0; i <= n-k; i++)     // rows in cost
        {
            int j = k + i;
            cost[i][j] = INT_MAX;

            for(int s = i; s < j; s++)     // intermediate k value
            {
                if(i == j)
                    cost[i][j] = 0;
                else
                {
                    float temp = cost[i][s] + cost[s+1][j] + weight[i][j];
                    if(temp < cost[i][j])
                        cost[i][j] = temp;
                }
            }
        }
    }

    cout << "Optimal Cost: " << cost[0][n] << endl;

    return 0;
}
