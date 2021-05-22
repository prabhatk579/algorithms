/*
    Given an array of n elements, give an algorithm for checking whether there are any
    duplicate elements in the array or not? in O(nlogn) time.
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
int DuplicateCheck(int a[], int l , int h){
    int start = 0, count = 0, j = 0;
    mergeSort(a,l,h); 
    for(int i = l; i <= h-1; i++){
        if(a[i]!=a[start]){
            printf("%d has occurred %d times \n",a[start],count);
            count=j+1;
            start=i;
        }
        else count++;
    }
    printf("%d has occurred %d times \n",a[start],count);
}
int main(){
    int a[] = {1,1,1,3,4,5,6,7};
    int n = sizeof(a)/sizeof(a[0]);
    DuplicateCheck(a,0,n);
    return 0;
}
