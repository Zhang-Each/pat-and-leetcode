def friend(x):
    res = 0
    for i in x:
        res += int(i)
    return res
n = int(input())
nums = [friend(x) for x in input().split(' ')]
nums = sorted(set(nums))
print(len(nums))
print(' '.join([str(x) for x in nums]))