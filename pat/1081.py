n = int(input())
nums = [(int(x.split('/')[0]), int(x.split('/')[1])) for x in input().split(' ')]
x, y = 0, 1
for i in nums:
    y *= i[1]
for i in nums:
    x += int(i[0] * y / i[1])
integer = x // y
x -= integer * y
for i in range(min(x, y), 0, -1):
    if x % i == 0 and y % i == 0:
        x, y = x / i, y / i
        break
if x == 0:
    print(integer)
else:
    if integer != 0:
        print(integer, end=' ')
    print(str(int(x)) + '/' + str(int(y)))
