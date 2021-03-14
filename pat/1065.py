n = int(input())
for i in range(n):
    a, b, c = [int(x) for x in input().split(' ')]
    if a + b > c:
        print("Case #" + str(i + 1) + ": true")
    else:
        print("Case #" + str(i + 1) + ": false")