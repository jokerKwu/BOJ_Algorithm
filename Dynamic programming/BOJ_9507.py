dp=[1,1,2,4]
for i in range(4,68):
    dp.append(dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4])
testCase=int(input())
for i in range(testCase):
    n =int(input())
    print(dp[n])

