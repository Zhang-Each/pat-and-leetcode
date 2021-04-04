/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int t[26] = {0};
        for (int i = 0; i < s.size(); i ++) {
            t[s[i] - 'a'] ++;
        }
        for (int i = 0; i < s.size(); i ++) {
            if (t[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

