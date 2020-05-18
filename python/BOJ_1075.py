N = input()
F = int(input())
tmp = int(N[:-2]+'00')

while True:
    if (tmp % F) == 0:
        print(str(tmp)[-2:])
        break
    tmp += 1