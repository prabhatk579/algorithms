#include <stdio.h>
int max(int a, int b){
    if(a > b)
        return a;
    else
	    return b;
}
void knapsackDPP(int W[], int V[], int M, int n){
	int A[n + 1][M + 1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=M; j++){
			A[i][j] = 0;
		}
    }
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= M; j++){
            if(i == 0 || j == 0)
				A[i][j] = 0;
			else if(W[i - 1] <= j)
				A[i][j] = max(V[i - 1] + A[i - 1][j - W[i - 1]], A[i - 1][j]);
			else
				A[i][j] = A[i - 1][j];
            // printf("%d  ",A[i][j]); //to see the knapsack filling table
		}
        //printf("\n");
	}
	printf("Max earning: %d\t", A[n][M]);
	printf("\nSelected Packs: ");
	while (n != 0){
		if (A[n][M] != A[n - 1][M]){
			printf("\nPackage %d with W = %d and Value = %d",n,W[n-1],V[n - 1]);
			M = M - W[n-1];
		}
		n--;
	}
}
int main(){
	int W[] = {10, 2, 1, 1, 4};
	int V[] = {4, 2, 1, 2, 10};
	int Max = 15;
	int n = sizeof(V) / sizeof(V[0]);
	knapsackDPP(W, V, Max, n);
}
