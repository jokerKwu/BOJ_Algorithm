N = int(input())
arr = list(map(int,input().split()))
date = []
for i in range(N):
    date.insert(arr[i]  , i + 1)
for i in range(N - 1, -1, -1):
    print(date[i], end= ' ')