n = int(input())
for i in range(n):
    num = input()
    cut = int(num[0: int(len(num) / 2)]) * int(num[int(len(num) / 2):])
    if cut != 0 and int(num) % cut == 0:
        print("Yes")
    else:
        print("No")