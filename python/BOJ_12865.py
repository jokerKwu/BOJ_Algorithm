import sys
input = sys.stdin.readline

N, K = map(int, input().split())
dp = [ [0]*(K+2) for _ in range(N+1) ]

weight = []
value = []
weight.append(0)
value.append(0)
for i in range(1, N+1):
    w, v = map(int, input().split())
    weight.append(w)
    value.append(v)

for i in range(1, N+1):
    for j in range(1, K+1):
        if j >= weight[i]:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
        else:
            dp[i][j] = dp[i-1][j]

print(dp[N][K])