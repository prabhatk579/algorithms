#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j){
	int s = 0;
	for(int k = i; k <=j; k++)
	    s += freq[k];
	return s;
}
int optimalSearchTree(int keys[], int freq[], int n){
	int c = 0;
    int cost[n][n]; // cost[i][j] = OBST that can be formed from i to j
	for(int i = 0; i < n; i++)
		cost[i][i] = freq[i]; // for i to i, cost is equal to frequency of the key	
	for(int L=2; L<=n; L++){ // L is chain length.
		for(int i=0; i<=n-L+1; i++){
			int j = i+L-1;
			cost[i][j] = INT_MAX;
			for(int r=i; r<=j; r++){
                if(r > i)
                    c = cost[i][r - 1];
                if(r < j)
                    c += cost[r + 1][j];
                else
                    c += 0;
                c += sum(freq, i, j);
			if(c < cost[i][j])
				cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}
int main(){
	int keys[] = {1, 2, 4};
	int freq[] = {4, 2, 5};
	int n = sizeof(keys)/sizeof(keys[0]);
	printf("Cost of Optimal BST is %d ",optimalSearchTree(keys, freq, n));
	return 0;
}
