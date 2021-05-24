def JobSequencing(arr,t):
    n=len(arr)
    for i in range(n):
        for j in range(n-1-i):
            if(arr[j][2] < arr[j+1][2]):
                arr[j], arr[j+1] = arr[j+1], arr[j]
    
    result = [False]*t
    job = ['-1']*t
    
    for i in range(len(arr)):
        for j in range(min(t-1,arr[i][1]-1),-1,-1):
            if(result[j] is False):
                result[j] = True
                job[j] = arr[i][0]
                break
    
    print(*job)

n = int(input())
arr = []
for i in range(n):
    d, p = map(int, input().split())
    arr.append([i+1, d, p])
print()
JobSequencing(arr, n)