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
void Display(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int a[] = {5,4,3,2,1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Given array is: \n");
    Display(a, n);
    QuickSort(a, 0, n - 1);
    printf("\nSorted array is: \n");
    Display(a, n);
    return 0;
}
