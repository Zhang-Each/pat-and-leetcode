nums = input().split(' ')[1: ]
nums_dict = {}
for i in range(len(nums)):
    if nums[i] not in nums_dict.keys():
        nums_dict[nums[i]] = []
    nums_dict[nums[i]].append(i)
found = 0
for i in nums_dict.keys():
    if len(nums_dict[i]) == 1:
        print(nums[nums_dict[i][0]])
        found = 1
        break
if found == 0:
    print("None")