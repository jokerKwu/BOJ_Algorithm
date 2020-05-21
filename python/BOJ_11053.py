import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
dp = [0 for i in range(n)]
dp[0] = 1
for i in range(1, n):
    for j in range(i):
        if dp[i] < dp[j] and arr[i] > arr[j]:
            dp[i] = dp[j]
    dp[i] += 1

print(max(dp))