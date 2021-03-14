def isPalindromlic(s: int):
    l = str(s)
    t = l[:: -1]
    return t == l

def add(s: int):
    res = s + int(str(s)[:: -1])
    print(str(s) + " + " + str(str(s)[:: -1]) + " = " + str(res))
    return s + int(str(s)[:: -1])

n = int(input())
step = 10
found = 0
if isPalindromlic(n):
    print(str(n) + " is a palindromic number.")
    found = 1
else:
    for i in range(1, step + 1):
        n = add(n)
        if isPalindromlic(n):
            print(str(n) + " is a palindromic number.")
            found = 1
            break
if found == 0:
    print("Not found in 10 iterations.")