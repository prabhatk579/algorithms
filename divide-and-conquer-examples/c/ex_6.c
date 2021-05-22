/*
    Given a sorted array of non-repeated integers A[1...n], n > 1 then check whether there is
    an index i for which A[i] = i. Give an algorithm that runs in O(logn) time 
*/

#include <stdio.h>
int BS(int a[], int l, int h){
    if(h >= l){
        int mid = (l + h)/2;
        if(a[mid] == mid){
            return mid;
        }
        if(a[mid] < mid){
            return BS(a, mid + 1, h);
        }
        if(a[mid] > mid){
            return BS(a, l, mid - 1);
        }
    }
    return -1;
}
int main(){
    int a[10] = {-2, -1, 0, 1, 2, 4, 5, 7, 11, 13};
    int n = sizeof(a)/sizeof(a[0]);
    int result = BS(a, 0, n-1);
    if(result != -1){
        printf("A[i] = i at Point: %d", result);
    }
    else{
        printf("There is not element satisfying A[i] = i");
    }
    return 0;
}
