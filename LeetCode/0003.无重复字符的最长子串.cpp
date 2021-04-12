/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <map>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    // 经典题，双指针做法，复杂度是线性的
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int left = 0, right = 0, res = 0;
        while (right < s.size()) {
            mp[s[right]] ++;
            while (mp[s[right]] >= 2) {
                mp[s[left ++]] --;
            }
            res = max(res, right - left + 1);
            right ++;
        }
        return res;
    }
};
// @lc code=end

