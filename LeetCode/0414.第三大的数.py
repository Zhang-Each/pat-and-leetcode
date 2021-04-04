#
# @lc app=leetcode.cn id=414 lang=python3
#
# [414] 第三大的数
#

# @lc code=start
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        s  = set(nums)
        if len(s) <= 2:
            return max(s)
        s.remove(max(s))
        s.remove(max(s))
        return max(s)
# @lc code=end

