#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target < nums[0]:
            return 0
        elif target > nums[-1]:
            return len(nums)
        for i in range(len(nums)):
            if nums[i] == target:
                return i
            elif i != len(nums) - 1 and nums[i] < target and nums[i + 1] > target:
                return i + 1
        return -1

# @lc code=end

