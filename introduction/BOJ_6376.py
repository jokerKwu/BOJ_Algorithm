def fact(num):
    if num==1or num==0:
        return 1
    else:
        return fact(num-1)*num

print('n e')
print('- -----------')
for i in range(0,3):
    res=0
    if i==2:
        for j in range(0, i + 1):
            res += float(1 / fact(j))
        print(i,res)
    else:
        for j in range(0,i+1):
            res+=int(1/fact(j))
        print(i,res)
for i in range(3,10):
    res=0
    for j in range(0,i+1):
        res+=1/fact(j)
    print (i,'%.9f'%res)