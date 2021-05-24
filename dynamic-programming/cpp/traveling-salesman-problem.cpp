// Traveling Salesman Problem


#include <bits/stdc++.h>

using namespace std;

int arr[10][10], completed[10], n, cost = 0;

void takeInput()
{
	int i, j;

	cout << "Enter number of villages: ";
	cin >> n;
	cout << endl << "Enter the cost matrix: " << endl;

	for(i = 0; i < n; i++)
    {
		for(j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            arr[i][j] = k;
        }
		completed[i] = 0;
	}

	cout << endl << endl << "The cost list is: " << endl;

	for(i = 0; i < n; i++)
    {
		for(j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            arr[i][j] = k;
        }
	}
}

int least(int c)
{
	int i, nc = 999;
	int min = 999, kmin;

	for(i = 0; i < n; i++)
    {
		if((arr[c][i] != 0) && (completed[i] == 0))
			if(arr[c][i] + arr[i][c] < min)
			{
				min = arr[i][0] + arr[c][i];
				kmin = arr[c][i];
				nc = i;
			}
	}

	if(min != 999)
		cost += kmin;
	return nc;
}

void mincost(int city)
{
	int i, ncity;
	completed[city] = 1;
	cout << city + 1 << " --> ";

	ncity = least(city);

	if(ncity == 999)
    {
		ncity = 0;
		cout << ncity + 1 << " ";
		cost += arr[city][ncity];
		return;
	}

	mincost(ncity);
}

int main()
{
	takeInput();

	cout << endl << endl << "The path is: " << endl;

	mincost(0);

	cout << endl << endl << "The minimum cost is " << cost << endl;

	return 0;
}
