m, n = [int(x) for x in input().split(' ')]
color = {}
for i in range(n):
    for j in [x for x in input().split(' ')]:
        if j not in color.keys():
            color[j] = 0
        color[j] += 1
color = [(k, color[k]) for k in color.keys()]
print(max(color, key=lambda x: x[1])[0])
