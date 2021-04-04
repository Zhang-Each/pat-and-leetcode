#
# @lc app=leetcode.cn id=326 lang=python3
#
# [326] 3的幂
#

# @lc code=start
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        res = int(round(math.log(n, 3)))
        return 3 ** res == n
# @lc code=end

