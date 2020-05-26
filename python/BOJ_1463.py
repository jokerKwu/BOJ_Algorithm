import sys
n = int(sys.stdin.readline())
dp = [0 for _ in range(n+1)]
arr = [n]
while arr or dp[0] != 0:
    c_n = arr.pop()
    if c_n == 1:
        break
    if c_n % 2 == 0 and dp[c_n//2] == 0:
        dp[c_n//2] = dp[c_n] + 1
        arr = [c_n // 2] + arr
    if c_n % 3 == 0 and dp[c_n//3] == 0:
        dp[c_n//3] = dp[c_n] + 1
        arr = [c_n // 3] + arr
    if dp[c_n - 1] == 0:
        dp[c_n - 1] = dp[c_n] + 1
        arr = [c_n-1] + arr
print(dp[1])
