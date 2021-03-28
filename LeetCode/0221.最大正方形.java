/*
 * @lc app=leetcode.cn id=221 lang=java
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int row = matrix.length, col = matrix[0].length, len = 0;
        int[][] dp = new int[row + 1][col + 1];
        for (int i = 1; i <= row; i ++) {
            for (int j = 1; j <= col; j ++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1]));
                    len = Math.max(len, dp[i][j]);
                }
            }
        }
        return len * len;
    }
}
// @lc code=end

