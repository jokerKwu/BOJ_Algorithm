import sys
input = sys.stdin.readline

N = int(input())
date = list(map(int,input().split()))
date.insert(0, 0)

dp = [ 1 for _ in range(1002) ]
dp[1] = 1
answer_value = dp[1]
for i in range(2, N+1):
    for j in range(1, i):
        if date[i] > date[j] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1
            if dp[i] > answer_value:
                answer_value = dp[i]

value = answer_value
answer_arr = []
for i in range(N, 0, -1):
    if dp[i] == value:
        answer_arr.append(date[i])
        value -= 1

print(answer_value)
for i in range(len(answer_arr)-1, -1, -1):
    print(answer_arr[i], end=' ')


