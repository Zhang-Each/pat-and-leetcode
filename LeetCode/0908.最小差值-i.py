#
# @lc app=leetcode.cn id=908 lang=python3
#
# [908] 最小差值 I
#

# @lc code=start
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        return max(max(A) - min(A) - 2 * K, 0)
        
# @lc code=end

