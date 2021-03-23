/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
    public:
        // 经典题，双指针做法，复杂度是线性的
        int lengthOfLongestSubstring(string s) {
            map<char, int> mp;
            int maxLen = 0;
            for (int i = 0, j = 0; i < s.size(); i ++) {
                mp[s[i]] += 1;
                while (mp[s[i]] >= 2) {
                    mp[s[j ++]] --;
                }
                maxLen = max(maxLen, i - j + 1);
            }
            return maxLen;
        }
    };
// @lc code=end

