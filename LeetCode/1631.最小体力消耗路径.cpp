/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int res[101][101] = {0};
        int row = heights.size(), col = heights[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    
                }
            }
        }
    }
};
// @lc code=end

