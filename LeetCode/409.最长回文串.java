/*
 * @lc app=leetcode.cn id=409 lang=java
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
    public int longestPalindrome(String s) {
        int[] w = new int[128];
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            w[s.charAt(i)] ++;
        }
        for (int i = 0; i < w.length; i ++) {
            res += w[i] / 2 * 2;
            if (res % 2 == 0 && w[i] % 2 == 1) {
                res += 1;
            }
        }
        return res;
    }
}
// @lc code=end

