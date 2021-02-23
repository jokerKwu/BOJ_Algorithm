date = list(input())
for c in date:
    if c.islower() == True: print(c.upper(),end="")
    else: print(c.lower(),end="")