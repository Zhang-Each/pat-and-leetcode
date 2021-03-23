/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string temp;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        travel(digits, 0);
        return res;
    }
    void travel(string s, int len) {
        if (len == s.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < mp[s[len] - '0'].size(); i++) {
            temp.push_back(mp[s[len] - '0'][i]);
            travel(s, len + 1);
            temp.pop_back();
        }
    }
};
// @lc code=end

