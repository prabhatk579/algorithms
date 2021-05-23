def linearsearch(arr, x):
   for i in range(len(arr)):
      if arr[i] == x:
         return i
   return -1
a = list(map(int, input().split()))
k = int(input())
print("element found at index "+str(linearsearch(a,k)))

 