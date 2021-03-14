M, N, S = [int(x) for x in input().split()]
forward = ['start']
for i in range(M):
    a = input()
    forward.append(a)
award = []
while S <= M:
    while forward[S] in award:
        S += 1
    award.append(forward[S])
    S += N
if len(award) == 0:
    print('Keep going...')
else:
    for i in award:
        print(i)
