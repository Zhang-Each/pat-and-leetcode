/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k >= 10 || n > 45) {
            return res;
        }
        for (int i = 1; i <= 9; i ++) {
            temp.push_back(i);
            travel(n - i, i, k);
            temp.pop_back();
        }
        return res;
    }

    void travel(int target, int last, int k) {
        if (target == 0 && temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = last + 1; i <= 9; i ++) {
            if (target - i >= 0) {
                temp.push_back(i);
                travel(target - i, i, k);
                temp.pop_back();
            } else {
                break;
            }
        }
    }
};
// @lc code=end

