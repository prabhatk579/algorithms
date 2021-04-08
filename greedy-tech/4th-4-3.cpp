// Prim's Algorithm

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of nodes of a graph: ";
    cin >> n;

    int key[n], weight[n][n];

    cout << "Enter weights : ";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> weight[i][j];
    }

    // give default values
    bool MST[n];
    for(int i = 0; i < n; i++)
        MST[i] = false, key[i] = INT_MAX;

    // select 1 out of all
    key[0] = 0;
    int initial_i = 0, initial_j = 0;
    int min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(min > weight[i][j] && weight[i][j] != 0)
            {
                initial_i = i;
                initial_j = j;
                min = weight[i][j];
            }
        }
    }

    // assign visited to the selected
    MST[initial_i] = true;
    MST[initial_j] = true;
    key[initial_i] = true;
    key[initial_j] = true;

    cout << "Selected co-ordinates are: ( " << initial_i << ", " << initial_j << ")" << endl;
    cout << "Weight is: " << min << endl;

    weight[initial_i][initial_j] = 0;

    // selecting the min cost edge checking if it form cycle
    for(int i = 0; i < n-2; i++)
    {
        min = INT_MAX;
        for(int p = 0; p < n; p++)
        {
            for(int q = 0; q < n; q++)
            {
                if(MST[p] == false && MST[q] == true && weight[p][q] != 0)
                {
                    if(min > weight[p][q])
                    {
                        min = weight[p][q];
                        initial_i = p;
                        initial_j = q;
                    }
                }
            }
        }
        MST[initial_i] = true;
        key[initial_i] = true;
        cout << "Selected co-ordinates are: ( " << initial_i << ", " << initial_j << ")" << endl;
        cout << "Weight is: " << min << endl;
    }

    return 0;
}
