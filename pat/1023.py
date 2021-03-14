num = input()
new_num = str(int(num) * 2)
if set(num) == set(new_num):
    print("Yes")
else:
    print("No")
print(new_num)