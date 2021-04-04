#
# @lc app=leetcode.cn id=342 lang=python3
#
# [342] 4的幂
#

# @lc code=start
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        res = int(round(math.log(n, 4)))
        return 4 ** res == n
# @lc code=end

