import math
def prime(x):
    x = int(x)
    if x <= 1:
        return False
    if x == 2 or x == 3:
        return True
    for i in range(2, int(math.sqrt(x / 2)) + 1):
        if x % i == 0:
            return False
    return True

s = input()
flag = True
for i in range(len(s)):
    x = s[i:]
    if prime(x):
        print(x, "Yes")
    else:
        print(x, "No")
        flag = False
if flag == True:
    print("All Prime!")