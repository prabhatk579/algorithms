# recursive binary search
def binary_search(arr, left, hi, key):
    if hi >= left:
        m = (hi + left) // 2
        if arr[m] == key:
            return m
        elif arr[m] > key:
            return binary_search(arr, left, m - 1, key)
        else:
            return binary_search(arr, m + 1, hi, key)
 
a = list(map(int, input().split()))
k = int(input())
x = binary_search(a, 0, len(a)-1, k)

if x != -1:
    print(x)