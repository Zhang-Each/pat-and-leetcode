n = int(input())
words, res = [], ""
length = 256
for i in range(n):
    word = input()[:: -1]
    words.append(word)
    if len(word) < length:
        length = len(word)
end = False
for i in range(length):
    for j in range(n):
        if words[j][i] != words[0][i]:
            end = True
    if end == False:
        res += words[0][i]
    else:
        break
if res != "":
    print(res[:: -1])
else:
    print("nai")