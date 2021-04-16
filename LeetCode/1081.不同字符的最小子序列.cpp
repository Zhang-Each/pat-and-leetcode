/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, int> have;
        stack<char> st;
        for (int i = 0; i < s.size(); i ++) {
            if (have[s[i]] == 1) {
                continue;
            }
            while (!st.empty() && st.top() > s[i] && s.find_last_of(st.top()) > i) {
                have[st.top()] = 0;
                st.pop();
            }
            st.push(s[i]);
            have[s[i]] = 1;
        }
        string res = "";
        while (st.size() > 0) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

