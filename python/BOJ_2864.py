import sys
input = sys.stdin.readline
a, b = map(str, input().split())
a = str(a).replace('6','5')
b = str(b).replace('6','5')
print(int(a)+int(b), end=' ')
a = str(a).replace('5','6')
b = str(b).replace('5','6')
print(int(a)+int(b), end=' ')