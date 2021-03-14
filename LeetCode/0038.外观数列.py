#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#

# @lc code=start
class Solution:
    def countAndSay(self, n: int) -> str:
        array = ["1", "11", "21", "1211", "111221"]
        if n <= 5:
            return array[n - 1]
        start = 5
        while start < n:
            num = array[start - 1]
            res = ""
            count = 1
            for i in range(0, len(num)):
                if i != len(num) - 1 and num[i] == num[i + 1]:
                    count += 1
                else:
                    res += str(count) + str(num[i])
                    count = 1
            start += 1
            array.append(res)
        return array[n - 1]

# @lc code=end

