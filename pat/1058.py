m, n = [y.split('.') for y in input().split(' ')]
m, n = [int(x) for x in m], [int(x) for x in n]
res = 17 * 29 * (m[0] + n[0]) + 29 * (m[1] + n[1]) + m[2] + n[2]
res_list = [int(res / (17 * 29)), int(int(res / 29) % 17), res % 29]
print('.'.join([str(x) for x in res_list]))