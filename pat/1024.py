def isPalindromlic(s: int):
    l = str(s)
    t = l[:: -1]
    return t == l

def add(s: int):
    return s + int(str(s)[:: -1])

n, step = [int(x) for x in input().split(' ')]
found = 0
if isPalindromlic(n):
    print(n)
    print(0)
    found = 1
else:
    for i in range(1, step + 1):
        n = add(n)
        if isPalindromlic(n):
            print(n)
            print(i)
            found = 1
            break
if found == 0:
    print(n)
    print(step)