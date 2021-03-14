#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        number = ''.join(str(s) for s in digits)
        number = int(number) + 1
        return [int(x) for x in list(str(number)) ]
# @lc code=end

