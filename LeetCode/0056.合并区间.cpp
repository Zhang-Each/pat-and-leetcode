/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        if (v1[0] != v2[0]) {
            return v1[0] < v2[0];
        }
        return v1[1] > v2[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& s) {
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

