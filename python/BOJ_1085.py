arr = list(map(int,input().split()))
print(min(arr[0],arr[1],abs(arr[0]-arr[2]), abs(arr[1]-arr[3])))