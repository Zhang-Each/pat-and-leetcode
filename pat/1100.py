n = int(input())
first = ["tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"]
second = ["tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"]
num_dict = {"tret": 0, "jan": 1, "feb": 2, "mar": 3, "apr": 4, "may": 5, "jun": 6, "jly": 7, "aug": 8, 
    "sep": 9, "oct": 10, "nov": 11, "dec": 12, "tam": 13, "hel": 26, "maa": 39, "huh": 52, "tou": 65, 
    "kes": 78, "hei": 91, "elo": 104, "syy": 117, "lok": 130, "mer": 143, "jou": 156}
for i in range(n):
    s = input()
    if s.isdigit():
        s = int(s)
        a, b = int(s / 13), s % 13
        if a != 0:
            print(second[a], first[b])
        else:
            print(first[b]);
    else:
        res = 0
        for i in s.split(' '):
            res += num_dict[i]
        print(res)