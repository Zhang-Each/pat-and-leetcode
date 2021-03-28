/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        if (v1[0] != v2[0]) {
            return v1[0] < v2[0];
        }
        return v1[1] > v2[1];
    }
    // 很naive地继承了0056的解法，插入一个新的然后重新合并
    vector<vector<int>> insert(vector<vector<int>>& s, vector<int>& newInterval) {
        s.push_back(newInterval);
        sort(s.begin(), s.end(), cmp);
        vector<vector<int>> res;
        int left = s[0][0], right = s[0][1];
        for (int i = 1; i < s.size(); i ++) {
            if (s[i][0] > right) {
                vector<int> temp;
                temp.push_back(left);
                temp.push_back(right);
                res.push_back(temp);
                left = s[i][0];
                right = s[i][1];
            } else {
                right = max(right, s[i][1]);
            }
        }
        vector<int> temp;
        temp.push_back(left);
        temp.push_back(right);
        res.push_back(temp);
        return res;
    }
};
// @lc code=end

