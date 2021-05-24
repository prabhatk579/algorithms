def binarySearch(arr, l, r, x):
 
    while l <= r:
 
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1
 
a = list(map(int, input().split()))
k = int(input())
x = binarySearch(a, 0, len(a)-1, k)

if x != -1:
    print(x)
 