/*
 * @lc app=leetcode.cn id=91 lang=java
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
    private int num(char x) {
        return x - '0';
    }
    public int numDecodings(String s) {
        if (s.charAt(0) == '0' || s.length() <= 1) {
            return s.charAt(0) == '0' ? 0 : 1;
        }
        int[] dp = new int[s.length()];
        dp[0] = 1;
        int head = 10 * num(s.charAt(0)) + num(s.charAt(1));
        if (head <= 26) {
            dp[1] = s.charAt(1) == '0' ? 1 : 2;
        } else if (s.charAt(1) != '0') {
            dp[1] = 1;
        }
        for (int i = 2; i < s.length(); i ++) {
            int number = 10 * num(s.charAt(i - 1)) + num(s.charAt(i));
            if (s.charAt(i) != '0') {
                dp[i] += dp[i - 1];
            }
            if (number <= 26 && number >= 10) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length() - 1];
    }
}
// @lc code=end

