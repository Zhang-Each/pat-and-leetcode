import re
from collections import Counter
s = input()
new_s = re.findall('([0-9|a-z|A-Z]+)', s)
words = [x.lower() for x in new_s]
dic = Counter(words)
temp = sorted([[dic[key], key] for key in dic], key = lambda x:(-x[0], x[1]))
print(temp[0][1], temp[0][0])