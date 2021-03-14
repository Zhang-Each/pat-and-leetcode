#
# @lc app=leetcode.cn id=187 lang=python3
#
# [187] 重复的DNA序列
#

# @lc code=start
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        dna = {}
        for i in range(len(s) - 9):
            if s[i: i + 10] in dna.keys():
                dna[s[i: i + 10]] += 1
            else:
                dna[s[i: i + 10]] = 1
        res = []
        for i in dna.keys():
            if dna[i] >= 2:
                res.append(i)
        return res
# @lc code=end

