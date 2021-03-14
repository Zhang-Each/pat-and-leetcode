n = int(input())
res = []
for i in range(n):
    no, p = input().split(' ')
    new_p = p.replace('1', '@').replace('0', '%').replace('l', 'L').replace('O', 'o')
    if p != new_p:
        res.append((no, new_p))
if len(res) == 0 and n > 1:
    print("There are", n, "accounts and no account is modified")
elif len(res) == 0 and n == 1:
    print("There is 1 account and no account is modified")
else:
    print(len(res))
    for i in range(len(res)):
        print(res[i][0], res[i][1])