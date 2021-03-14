/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        if (s.size() < 3) {
            return res;
        }
        int start = 0, end = 0;
        while (end < s.size()) {
            if (s[start] != s[end]) {
                if (end - start >= 3) {
                    vector<int> temp({start, end - 1});
                    res.push_back(temp);
                }
                start = end;
            }
            end++;
        }
        if (end - start >= 3) {
            vector<int> temp({start, end - 1});
            res.push_back(temp);            
        }
        return res;
    }
};
// @lc code=end

