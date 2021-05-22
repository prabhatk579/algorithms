#include <stdio.h>
int BSNR(int a[], int l, int h, int x){
    while(l <= h){
        int mid = (l + h)/2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] < x){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1;
}
int main(){
    int a[] = {5,10, 20, 30, 35, 100, 110};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 10;
    int result = BSNR(a, 0, n - 1, x);
    if(result == -1){
        printf("Element is not present in array");
    }
    else{
        printf("Element is present at index %d \n\t\tOR\nAlternatively %d location of array", result, result + 1);
    }
}
