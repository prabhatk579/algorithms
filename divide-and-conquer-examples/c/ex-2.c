/*
    Given an array of n elements. Find whether there are three elements in the array such
    that their sum is equal to given element K or not? in O(n^2) time.
*/

#include <stdio.h>
#define inf 999999
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void QuickSort(int a[], int l, int h){
int p, q, pivot, temp;
if(l < h){
    pivot = l;
    p = l;
    q = h;
    while(p < q){
        while(a[p] <=a [pivot] && p < inf)
            p++;
        while(a[q] > a[pivot])
            q--;
        if(p < q){
            swap(a, p, q);
        }
    }
    swap(a, pivot, q);
    QuickSort(a, l, q - 1);
    QuickSort(a, q + 1, h);
    }
}
int findtriplets(int A[], int arr_size, int sum){
	int l = 0, r = arr_size;
	QuickSort(A, l, r);
	for(int i = 0; i < arr_size - 2; i++){
		l = i + 1;
		r = arr_size - 1;
		while (l < r){
			if(A[i] + A[l] + A[r] == sum){
				printf("Triplet is (%d, %d, %d) and sum is %d \n", A[i], A[l], A[r], sum);
				return 1;
			}
			else if (A[i] + A[l] + A[r] < sum)
				l++;
			else // A[i] + A[l] + A[r] > sum
				r--;
		}
	}
	return -1;
}
int main(){
	int a[] = {1, 4, 45, 6, 10, 8};
	int sum = 22;
	int n = sizeof(a) / sizeof(a[0]);
	int present = findtriplets(a, n, sum);
    if(present == -1)
        printf("Sum of three element is not equal to the given elemet K = %d", sum);
    else if(present == 1)
        printf("There are three element having sum equal to given element K = %d", sum);
	return 0;
}
