N, P = map(int,input().split())

answer = {}
def calc(n, p):
    tmp = 0
    for i in range(len(str(n))):
        tmp += pow(int(str(n)[i]), p)
    return tmp
t = N
cnt = 0
answer[N] = 0

while True:
    t = calc(t, P)
    if t in answer:
        break
    cnt += 1
    answer[t] = cnt
print(answer[t])