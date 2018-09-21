def t(n):
    res=0
    while n!=0:
        res=res+int(n%10)
        n=int(n/10)
    return int(res)
def tw(n):
    res=0
    while n!=0:
        res=res+int(n%12)
        n=int(n/12)
    return int(res)
def ts(n):
    res=0
    while n!=0:
        res=res+int(n%16)
        n =int(n/16)
    return int(res)
for i in range(1000,10000):
    if t(i)==tw(i) and ts(i)==t(i):
        print(i)
