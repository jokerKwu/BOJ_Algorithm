t = int(input())
for i in range(t):
    num, s = input().split()
    text = ''
    for j in s:
        text += int(num) * j
    print(text)