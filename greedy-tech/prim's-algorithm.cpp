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
        MST[i] = false, key[i] = true;

    // select 1 out of all
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
    key[initial_i] = false;
    key[initial_j] = false;

    cout << "Selected co-ordinates are: ( " << initial_i << ", " << initial_j << ")" << endl;
    cout << "Weight is: " << min << endl;

    weight[initial_i][initial_j] = 0;

    // selecting the min cost edge checking if it form cycle
    for(int i = 0; i < n-2; i++)               // number of vertices
    {
        min = INT_MAX;
        for(int p = 0; p < n; p++)             // vertex is initially not selected but now selecting
        {
            for(int q = 0; q < n; q++)         // the selected vertex from which we have to draw path
            {
                if(MST[p] == false && MST[q] == true && weight[p][q] != 0)            // weight != 0 coz : their should be a path
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
        key[initial_i] = false;
        cout << "Selected co-ordinates are: ( " << initial_i << ", " << initial_j << ")" << endl;
        cout << "Weight is: " << min << endl;
    }

    return 0;
}

