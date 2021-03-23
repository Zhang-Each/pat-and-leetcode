/*
 * @lc app=leetcode.cn id=5 lang=java
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        boolean[][] dp = new boolean[s.length()][s.length()];
        int res = 0, maxi = 0, maxj = 0;
        for (int i = s.length() - 1; i >= 0; i --) {
            dp[i][i] = true;
            for (int j = i + 1; j < s.length(); j ++) {
                if (j == i + 1) {
                    dp[i][j] = s.charAt(i) == s.charAt(j);
                } else {
                    dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i + 1 > res) {
                    maxi = i;
                    maxj = j;
                    res = j - i + 1;
                }
            }
        }
        return s.substring(maxi, maxj + 1);
    }
}

// @lc code=end

