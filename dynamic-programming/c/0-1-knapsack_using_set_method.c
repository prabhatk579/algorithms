#include <stdio.h>
int max(int a, int b){
    if(a > b)
        return a;
    else
	    return b;
}
int knapSack(int W, int wt[], int val[], int n){
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}
int main(){
	int val[] = {10, 2, 1, 1, 4};
	int wt[] = {4, 2, 1, 2, 10};
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	printf("Max Earning: %d", knapSack(W, wt, val, n));
	return 0;
}
