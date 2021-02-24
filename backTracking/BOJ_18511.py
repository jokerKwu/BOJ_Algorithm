K, N = map(int,input().split())
date = list(input().split())
answer = 0
def backtracking(value):
    global K
    global answer
    if value > K:
        return
    answer = max(value, answer)
    for n in date:
        tmp = int(str(value) + str(n))
        backtracking(tmp)
    return

backtracking(0)
print(answer)
