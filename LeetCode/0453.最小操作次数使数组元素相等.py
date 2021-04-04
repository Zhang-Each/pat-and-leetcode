#
# @lc app=leetcode.cn id=453 lang=python3
#
# [453] 最小操作次数使数组元素相等
#

# @lc code=start
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        res, num = 0, min(nums)
        for i in nums:
            res += i - num
        return res
# @lc code=end

