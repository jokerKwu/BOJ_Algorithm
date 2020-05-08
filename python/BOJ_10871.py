n,x = map(int,input().split())
arr = list(map(int,input().split()))
for i in arr:
    if x > i:
        print(i,end=' ')