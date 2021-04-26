// Quick Sort

#include <bits/stdc++.h>

using namespace std;

class Solution
{

    int partition(int arr[], int low, int high)
    {
       int pivot = arr[low];
       int i = low;
       int j = high+1;
       while(i<=j)
       {
		   do
		   {
			   i++;
		   }while(pivot>arr[i]);

		   do{
			   j--;
		   }while(pivot<arr[j]);

		   if(i<j)
           {
               int c=arr[i];
               arr[i]=arr[j];
               arr[j]=c;
           }
	   }

	   int c=arr[low];
	   arr[low]=arr[j];
       arr[j]=c;
	   return j;
    }

public:
    void quickSort(int arr[], int low, int high)
    {
        if(low < high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p -1);
            quickSort(arr, p+1, high);
        }
    }
};

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, k;
    cout << "Enter number of array elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = s;
    }

    cout << "Original Array: ";
    printArray(arr, n);

    Solution ob;
    ob.quickSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}




