/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }
    
    bool match(const char *s, const char *p) {
        if (*p == 0) {
            return *s == 0;
        }
        // 第一个是否匹配，如果第一个匹配就跳到下一个
        bool first = !(*s == 0) && (*s == *p || *p == '.');
        if (*(p + 1) == '*') {
            // 有*的时候可以匹配任意个数，这里要考虑0个的情况
            return match(s, p + 2) || (first && match(s + 1, p));
        } else {
            return first && match(s + 1, p + 1);
        }

    }
};
// @lc code=end

