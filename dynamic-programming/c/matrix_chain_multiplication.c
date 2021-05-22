#include <limits.h>
#include <stdio.h>
int MatrixChainOrder(int d[], int n){
	int m[n][n];
	int i, j, k, L, x;
	for(i = 1; i < n; i++)
		m[i][i] = 0;
	for(L = 2; L < n; L++){ // L is chain length.
		for(i = 1; i < n - L + 1; i++){
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++){
				x = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (x < m[i][j])
					m[i][j] = x;
			}
		}
	}
	return m[1][n - 1];
}
int main(){
	int a[] = {1, 2, 3, 4, 5, 1};
	int n = sizeof(a) / sizeof(a[0]);
	printf("Minimum number of multiplications are: %d ", MatrixChainOrder(a, n));
	return 0;
}
