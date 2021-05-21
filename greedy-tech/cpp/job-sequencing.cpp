// Job Sequencing with deadlines algorithm

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;
    int dead;
    int profit;
};

// to sort job according to profit
bool compare(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

class Solution
{
  public:

    vector <int> JobScheduling(Job arr[], int n)
    {
        std::sort(arr, arr +n, compare);

        bool freeSlot[n];

        vector <int> v;

        int day = 0, profit = 0;

        for(int i = 0; i < n; i++)
            freeSlot[i] = false;

        for(int i = 0; i < n; i++)
        {
            for(int j = min(n, arr[i].dead)-1; j >= 0; j--)
            {
                if(freeSlot[j] == false)
                {
                    day += 1;
                    profit += arr[i].profit;
                    freeSlot[j] = true;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(freeSlot[i] == true)
            {
                v.push_back(day);
                v.push_back(profit);
            }
        }
        return v;
    }
};

int main()
{
    int t;
    cout << "Number of test cases: ";
    cin >> t;

    while(t--)
    {
        int n;
        cout << "Size of array: ";
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        cout << "Job ID, Deadline, Profit are: ";
        for(int i = 0;i < n;i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        vector <int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
	return 0;
}
