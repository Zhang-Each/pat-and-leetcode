#
# @lc app=leetcode.cn id=767 lang=python3
#
# [767] 重构字符串
#

# @lc code=start
class Solution:
    def reorganizeString(self, s: str) -> str:
        word_dict = {}
        sum = 0
        max = 0
        for i in s:
            if i in word_dict.keys():
                word_dict[i] += 1
            else:
                word_dict[i] = 1
        len_dict = len(word_dict.keys())
        if len_dict == len(s):
            return s
        for i in word_dict.keys():
            sum += word_dict[i]
            max = word_dict[i] if word_dict[i] > max else max
        if sum - max < max - 1:
            return ""
        res, pos = ["0"] * len(s), 0
        sorted_word_dict = sorted(word_dict.items(), key=lambda x:x[1], reverse=True)
        for i in sorted_word_dict:
            for j in range(i[1]):
                res[pos] = i[0]
                pos += 2
                if pos >= len(s):
                    pos = 1
        return ''.join(res)

# @lc code=end

