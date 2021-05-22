/*
    Given an array of n elements, give an algorithm for finding the element which appears
    maximum number of times in the array in O(nlogn) time.
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
int MaxCount(int a[], int n){
    int count = 1, maxCount = 1, freq = a[0];
    mergeSort(a, 0, n);
    for(int i = 1; i < n; i++){
        if(a[i-1] == a[i])
            count++;
        else{
            if(count > maxCount){
                maxCount = count;
                freq = a[i-1];
            }
            count = 1;
        }
    }
    if(count > maxCount){
        maxCount = count;
        freq = a[n-1];
    }
    return freq;
}
int main(){
    int a[] = {1,1,1,8,7,3,2,5,4,2,10,3,3,3,4,5,6};
    int n = sizeof(a) / sizeof(a[0]);
    int max = MaxCount(a,n);
    printf("The maximum appearing element in the array is: %d", max);
    return 0;
}
