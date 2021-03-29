/*
 * @lc app=leetcode.cn id=647 lang=java
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
    public int countSubstrings(String s) {
        boolean[][] dp = new boolean[s.length()][s.length()];
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i --) {
            dp[i][i] = true;
            count += 1;
            for (int j = i + 1; j < s.length(); j ++) {
                if (j == i + 1) {
                    dp[i][j] = s.charAt(j) == s.charAt(i);
                } else {
                    dp[i][j] = s.charAt(j) == s.charAt(i) && dp[i + 1][j - 1];
                }
                if (dp[i][j]) {
                    count += 1;
                }
            }
        }
        return count;
    }
}
// @lc code=end

