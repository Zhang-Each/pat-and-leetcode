#
# @lc app=leetcode.cn id=165 lang=python3
#
# [165] 比较版本号
#

# @lc code=start
class Solution:
    def process(self, s: str):
        res = [int(x) for x in s.split('.')]
        return res
    
    def check(self, l, s):
        for i in range(s, len(l)):
            if l[i] != 0:
                return False
        return True

    def compareVersion(self, version1: str, version2: str) -> int:
        x, y = self.process(version1), self.process(version2)
        flag = 0
        print(x, y)
        if len(x) > len(y):
            flag = 1
        elif len(x) < len(y):
            flag = 2
        for i in range(min(len(x), len(y))):
            if x[i] < y[i]:
                return -1
            elif x[i] > y[i]:
                return 1
        if flag == 1 and not self.check(x, len(y)):
            return 1
        if flag == 2 and not self.check(y, len(x)):
            return -1
        return 0
# @lc code=end

