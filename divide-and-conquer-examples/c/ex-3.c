/*
    Let A and B be two arrays of n elements. Given a number K, draw an O(nlogn) time
    algorithm for determining whether there exists a ∈ A, b ∈ B such that a+b = K or not?
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
int hasArrayTwoCandidates(int a[], int b[], int n, int sum){
    int l, h; 
    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, n - 1);
    l = 0;
    h = n - 1;
    while (l < h) {
        if(a[l] + b[h] == sum)
            return 1;
        else if(a[l] + b[h] < sum || b[l] + a[h] < sum)
            l++;
        else if(b[l] + a[h] > sum || a[l] + b[h] > sum)
            h--;
    }
    return 0;
}
int main(){
    int a[] = {14, 21, 7, 5, -4, 2};
    int b[] = {1, 4, 45, 6, 10, -8};
    int x = -2;
    int n = sizeof(a) / sizeof(a[0]);
    if(hasArrayTwoCandidates(a, b, n, x))
        printf("Arrays has two elements such that 'a' belongs to array A and 'b' belongs to array B with given sum");
    else
        printf("Arrays doesn't have two elements such that 'a' belongs to array A and 'b' belongs to array B with given sum");
    return 0;
}
