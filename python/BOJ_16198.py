import sys
N = sys.stdin.readline()
arr = list(map(int, sys.stdin.readline().split()))
answer = 0
def select(value):
    if len(arr) == 2:
        global answer
        if answer < value:
            answer = value
            return 0
    for i in range(1,len(arr)-1):
        value += (arr[i-1]*arr[i+1])
        tmp = arr[i]
        del arr[i]
        select(value)
        arr.insert(i,tmp)
        value -= (arr[i-1]*arr[i+1])

select(0)
print(answer)


