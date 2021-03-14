s = input()
t = input()
res = []
for i in s:
    if i not in t and i.upper() not in res:
        res.append(i.upper())
for i in res:
    print(i, end='')