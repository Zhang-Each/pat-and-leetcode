/*
 * @lc app=leetcode.cn id=279 lang=java
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
    int minlen;
    public int numSquares(int n) {
        minlen = n;
        search(0, n);
        return minlen;
    }

    private void search(int len, int n) {
        if (n == 0) {
            minlen = len < minlen ? len : minlen;
            return;
        }
        if (len >= minlen) {
            return;
        }
        int start = (int)Math.sqrt(n);
        for (int i = start; i >= 1; i --) {
            search(len + 1, n - i * i);
        }
    }
}
// @lc code=end

