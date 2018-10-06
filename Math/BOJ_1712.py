str=input().split()
a=int(str[0])
b=int(str[1])
c=int(str[2])
if (c-b)>0:
    res=a/(c-b)
    print(int(res+1))
else:
    print(-1)