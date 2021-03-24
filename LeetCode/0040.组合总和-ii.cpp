/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        if (c.size() == 0 || c[0] > target) {
            return res;
        }
        travel(temp, c, 0, 0, target);
        return res;
    }
    void travel(vector<int> &temp, vector<int> c, int sum, int index, int target) {
        if (sum > target) {
            return;
        } else if (sum == target) {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < c.size(); i ++) {
            if (i > index && c[i] == c[i - 1]) {
                continue;
            }
            if (sum + c[i] <= target) {
                temp.push_back(c[i]);
                travel(temp, c, sum + c[i], i + 1, target);
                temp.pop_back();
            } else {
                break;
            }
        }
    }
};

// @lc code=end

