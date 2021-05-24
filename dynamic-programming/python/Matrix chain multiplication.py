dp = [[-1 for i in range(100)] for j in range(100)]
def matrixChain(p, i, j):
	if(i == j):
		return 0
	if(dp[i][j] != -1):
		return dp[i][j]
	dp[i][j] = 54897895379543943
	for k in range(i,j):
		dp[i][j] = min(dp[i][j], matrixChain(p, i, k) + matrixChain(p, k + 1, j)+ p[i - 1] * p[k] * p[j])
	return dp[i][j]

def MatrixChainOrder(p,n):
	i = 1
	j = n - 1
	return matrixChain(p, i, j)

A = list(map(int, input().split()))
print(MatrixChainOrder(A, len(A)))