// 0/1 Knapsack Problem

#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int knapSack(int W, int wt[], int val[], int n)
    {
       int dp[n+1][W+1];

       for(int i = 0; i <= n; i++)
       {
          dp[i][0] = 0;
       }

       for(int j = 0; j <= W; j++)
       {
          dp[0][j] = 0;
       }

       // i start from 1 becoz later i'm using i-1 while replacing
       for(int i = 1; i <= n; i++)
       {
           for(int j = 0; j <= W; j++)
           {
               if(wt[i-1] > j)
               {
                   dp[i][j] = dp[i-1][j];
               }
               else
               {
                   dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
               }
           }
       }

       return dp[n][W];
    }
};

int main()
 {
    int t;
    cout << "Enter number of test-cases: ";
    cin >> t;

    while(t--)
    {
        int n, w;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter total weights: ";
        cin >> w;

        int val[n];
        int wt[n];

        cout << endl << "Enter values: ";
        for(int i = 0; i < n; i++)
            cin >> val[i];

        cout << endl << "Enter weights: ";
        for(int i = 0; i < n; i++)
            cin >> wt[i];

        Solution ob;
        cout << endl << "Cost via 0/1 KnapSack Problem: " << ob.knapSack(w, wt, val, n) << endl;
    }

	return 0;
}

