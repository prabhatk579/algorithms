// Knapsack Problem

#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value;
    int weight;
};

// Function to compare
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

class Solution
{
public:
    double knapsack(int W, Item arr[], int n)
    {
        // sorting array according to value/weight
        sort(arr, arr+n, cmp);
        int u = 0;
        double val = 0.0;
        for(int i = 0; i < n; i++)
        {
            if(u + arr[i].weight <= W)
            {
                u += arr[i].weight;
                val += arr[i].value;
            }
            else
            {
                int remain = W - u;
                val += arr[i].value* ((double)remain / (double)arr[i].weight);
                break;
            }
        }
        return val;
    }
};

int main()
{
	int n, W;

	cout << "Enter number of elements in array: ";
	cin >> n;
	cout << "Enter size of bag: ";
	cin >> W;

	Item arr[n];

	cout << "Enter Value and Weight: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    Solution ob;
    cout << ob.knapsack(W, arr, n) << endl;

    return 0;
}
