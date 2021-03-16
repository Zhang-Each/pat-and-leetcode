/*
 * @lc app=leetcode.cn id=63 lang=java
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
    public int uniquePathsWithObstacles(int[][] s) {
        int[][] dp = new int[s.length][s[0].length];
        dp[0][0] = 1 - s[0][0];
        for (int i = 1; i < s.length; i++) {
            if (s[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1; i < s[0].length; i++) {
            if (s[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < s.length; i ++) {
            for (int j = 1; j < s[0].length; j ++) {
                if (s[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[s.length - 1][s[0].length - 1];
    }
}
// @lc code=end

