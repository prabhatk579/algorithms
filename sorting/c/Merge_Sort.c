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
    if (l < h){
        int mid = l + (h - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        SimpleMerge(a, l, mid, h);
    }
}
void Display(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int a[] = {30, 10, 35, 20, 110, 100, 5};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Given array is: \n");
    Display(a, n);
    mergeSort(a, 0, n - 1);
    printf("\nSorted array is: \n");
    Display(a, n);
    return 0;
}