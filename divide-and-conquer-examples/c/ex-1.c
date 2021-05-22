/*
    Given an array of n elements. Find whether there are two elements in the array such that
    their sum is equal to given element K or not? in O(nlogn) time.
*/

#include <stdio.h>
void SimpleMerge(int a[], int l, int m, int h){
    int i, j, k; 
    int n1 = m - l + 1;
    int n2 = h - m;
    int A[n1], B[n2];
    for(i = 0; i < n1; i++){
        A[i] = a[l + i]; //Left Sub Array
    }
    for(j = 0; j < n2; j++){
        B[j] = a[m + 1 + j]; //Right Sub array
    }
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(A[i] <= B[j]){
            a[k] = A[i];
            i++;
        }
        else{
            a[k] = B[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = A[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = B[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int h){
    if(l < h){
        int mid = l + (h - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        SimpleMerge(a, l, mid, h);
    }
}
int hasArrayTwoCandidates(int a[], int n, int sum){
    int l, h; 
    mergeSort(a, 0, n - 1);
    l = 0;
    h = n - 1;
    while(l < h){
        if (a[l] + a[h] == sum)
            return 1;
        else if(a[l] + a[h] < sum)
            l++;
        else // if(a[l] + a[h] > sum)
            h--;
    }
    return 0;
}
int main(){
    int a[] = {14, 21, 7, 5, -4, 2};
    int x = 12;
    int n = sizeof(a) / sizeof(a[0]);;
    if(hasArrayTwoCandidates(a, n, x))
        printf("Array has two elements with given sum");
    else
        printf("Array doesn't have two elements with given sum");
    return 0;
}
