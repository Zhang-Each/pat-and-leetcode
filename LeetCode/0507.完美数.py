#
# @lc app=leetcode.cn id=507 lang=python3
#
# [507] 完美数
#

# @lc code=start
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 2:
            return False
        sum = 0
        for i in range(1, int(math.sqrt(num)) + 1) :
            if num % i == 0:
                sum += i + int(num / i)
                print(i)
        return sum == 2 * num
# @lc code=end

