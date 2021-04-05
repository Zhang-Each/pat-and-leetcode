/*
 * @lc app=leetcode.cn id=97 lang=java
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
     public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) return false;

        char[]sub1 = s1.toCharArray();
        char[]sub2 = s2.toCharArray();
        char[] str = s3.toCharArray();

        boolean[][]dp = new boolean[sub1.length + 1][sub2.length + 1];
        dp[0][0] = true;

        for (int i = 0; i <= sub1.length; i++) {
            for (int j = 0; j <= sub2.length; j++) {
                if (i > 0 && sub1[i - 1] == str[i + j - 1] && dp[i - 1][j]) dp[i][j] = true;
                if (j > 0 && sub2[j - 1] == str[i + j - 1] && dp[i][j - 1]) dp[i][j] = true;
            }
        }

        return dp[sub1.length][sub2.length];
    }
}
// @lc code=end

