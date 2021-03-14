a = input()
b = input()
shop = {}
for i in a:
    if i not in shop.keys():
        shop[i] = 0
    shop[i] += 1
remain = []
for i in b:
    if i in shop.keys():
        if shop[i] >= 1:
            shop[i] -= 1
        else:
            remain.append(i)
    else:
        remain.append(i)
if remain == []:
    print("Yes", len(a) - len(b))
else:
    print("No", len(remain))
