n = int(input())
arr = list(map(int,input().split()))
res = 0

def prime(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

for i in range(n):
    if arr[i] == 1:
        continue
    elif arr[i] == 2:
        res += 1
    else:
        if prime(arr[i]):
            res += 1
print(res)