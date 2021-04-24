// Dijkstra's Algorithm

#include <bits/stdc++.h>

using namespace std;

void paths(int path[], int j){

	if(path[j] == -1)
    {
		return;
	}
	paths(path, path[j]);

	cout << j << " -> ";
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int weight[n][n];
    bool S[n] = {false};        // visited vertex
	bool NS[n] = {true};        // Non-visited Vertex
	int D[n];                   // for distance
	int X;                      // presently visited vertex
	int path[n];

	cout << endl << "Enter weight adjacency matrix" << endl;
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> weight[i][j];
        }
    }

    cout << endl << "Printing weight matrix" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && weight[i][j] == 0)
                weight[i][j] = INT_MAX;
            if(i == j)
                weight[i][j] = 0;
            cout << weight[i][j] << " ";
        }
        cout << endl;
    }

    int source;
    cout << endl << "Enter source vertex: ";
    cin >> source;

    for(int i = 0; i < n; i++)
    {
        S[i] = false;
        NS[i] = true;
        D[i] = INT_MAX;
    }

    D[source] = 0;
    X = source;

    for(int i = 0; i < n-1; i++)
    {
        int min_val = INT_MAX, min_vertex;
        for(int j = 0; j < n; j++)
        {
            if(S[j] == false && D[j] < min_val)
            {
                min_val = D[j];
                min_vertex = j;
            }
        }

        S[min_vertex] = true;
        NS[min_vertex] = false;
        X = min_vertex;

        for(int j = 0; j < n; j++)
        {
            if(S[j] == false && NS[j] == true)
            {
                D[j] = min(D[j], D[X] + weight[X][j]);
                if(D[j] == D[X]+weight[X][j])
					path[j] = X;
            }
        }
    }

    cout << endl << "Pairs \t\t Distance \t\t Paths" << endl;

	for(int i = 0; i < n; i++)
    {
        cout << source << " -> " << i;
        cout << "\t\t " << D[i];
        cout << "\t\t\t " << source << " -> ";
		paths(path, i);
		cout << "\b \b " << endl;
	}

    cout << endl << endl;

    return 0;
}

