testCase=int(input())
for i in range(testCase):
    num=int(input())
    idx=0
    while num!=0:
        if num&1:
            print(idx,end=" ")
        idx+=1
        num>>=1
