import collections

inStr = list(map(str, input().upper()))
cnt_arr = collections.Counter(inStr)
max_value = max(cnt_arr.values())
sorted(cnt_arr)
cnt = 0
answer = ''
for i in cnt_arr:
    if max_value == cnt_arr[i]:
        cnt += 1
        answer = i
        if cnt == 2:
            answer = '?'
            break
print(answer)