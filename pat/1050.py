s = input()
t = input()
res = ""
for i in s:
    if i not in t:
        res += i
print(res)