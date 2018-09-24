testCase=int(input())
for i in range(testCase):
    s=input()
    print('String #{0}'.format(i+1))
    for i in range(len(s)):
        if s[i]=='Z':
            print('A',end='')
        else:
            print(chr(ord(s[i])+1),end='')
    print(),print()
