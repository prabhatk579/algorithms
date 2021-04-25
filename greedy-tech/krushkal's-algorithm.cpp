// Krushkal's Algorithm

#include <bits/stdc++.h>

using namespace std;

int parent(int a[], int n)
{
	if(a[n] == n)
    {
		return n;
	}
	else
	{
		parent(a,a[n]);
	}
}

int find_set(int a[], int k)
{
	return parent(a,k);
}

void form_union(int a[], int n1, int n2, int n)
{
	int a1 = find_set(a, n1);
	int b1 = find_set(a, n2);
	for (int i = 0; i < n; ++i)
    {
		if(a[i] == b1 || a[i] == a1)
			a[i] = a1;
	}
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int sets[n], weight[n][n];
    bool S[n];

    cout << "Enter weights : ";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> weight[i][j];
    }

    for(int i = 0; i < n; i++)
        S[i] = false;

    // to find rank
    for(int i = 0; i < n; i++)
        sets[i] = i;

    for(int i = 0; i < n-1; i++)      // for vertices
    {
        int min = INT_MAX;
        int min_i, min_j;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(min > weight[j][k] && weight[j][k] != 0)
                {
                    if(find_set(sets, j) != find_set(sets, k))
                    {
                        min = weight[j][k];
                        min_i = i;
                        min_j = k;
                    }
                }
            }
        }
        S[min_i] = true;
        S[min_j] = true;
        form_union(sets, min_i, min_j, n);
        cout << "Points : (" << min_i << ", " << min_j << ") " << "Weights: " << weight[min_i][min_j] << endl;
    }

    return 0;
}

