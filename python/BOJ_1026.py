n = input()
a = [5,1,2,3,46,1,23]
a_arr = list(map(int,input().split()))
b_arr = list(map(int,input().split()))
a_arr.sort(reverse=True)
b_arr.sort()
res = 0
for i in range(int(n)):
    res += (a_arr[i]*b_arr[i])
print(res)