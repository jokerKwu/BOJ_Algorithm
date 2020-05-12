str_a = input()
str_b = input()
res = 0
for i in range(97,123):
    res += abs(str_a.count(chr(i))-str_b.count(chr(i)))
print(res)
