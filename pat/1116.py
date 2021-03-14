import math


def is_zhishu(num):
    if num == 2:
        return 1
    if num % 2 == 0:
        return 0
    for i in range(3, math.ceil(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return 0
    return 1


num = input()
rank_dic = {}
rank_set = set()
rank_num = 1
for i in range(int(num)):
    rank_dic[input()] = rank_num
    rank_num += 1
num = input()
for i in range(int(num)):
    s = input()
    if s not in rank_dic:
        print(s + ": Are you kidding?")
    elif s in rank_dic and s not in rank_set:
        if rank_dic[s] == 1:
            print(s + ": Mystery Award")
        elif is_zhishu(rank_dic[s]):
            print(s + ": Minion")
        else:
            print(s + ": Chocolate")
        rank_set.add(s)
    elif s in rank_set:
        print(s + ": Checked")