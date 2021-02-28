date = list(map(int,input().split()))
usedTime = int(input())

date[2] += usedTime

plusMinute = date[2] // 60
date[2] %= 60
date[1] += plusMinute
plusHour = date[1] // 60
date[1] %= 60
date[0] += plusHour

date[0] %= 24
print(date[0],date[1],date[2])
