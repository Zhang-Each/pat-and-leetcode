n = input()
res, l = [], len(n)
if n[0] == '-':
    n = n[1: ]
    res.append("Fu")
unit = ["", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"]
num = ["ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"]
for i in range(len(n)):
    if n[i] == '0':
        continue
    elif i > 0 and n[i] != '0' and n[i - 1] == '0':
        res.append("ling")
    res.append(num[int(n[i])])
    res.append(unit[len(n) - i - 1])
print(' '.join(res))