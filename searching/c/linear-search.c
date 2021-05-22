#include <stdio.h>
int linearsearch(int arr[], int size, int k){
    for(int i = 0; i <= size; i++){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
}
int main(){
    int a[] = {5,10, 20, 30, 35, 100, 110};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 10;
    int result = linearsearch(a, n - 1, x);
    if(result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d \n\t\tOR\nAlternatively %d location of array", result, result + 1);
    return 0;
}
