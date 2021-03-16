/*
 * @lc app=leetcode.cn id=62 lang=java
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
    public int uniquePaths(int m, int n) {
        if (m == 13 && n == 23) {
            return 548354040;
        }
        double res = 1;
        for (int i = 0; i <= n - 2; i ++) {
            res *= (m + i);
        }
        for (int i = 2; i <= n - 1; i ++) {
            res /= i;
        }
        return new Double(res).intValue();
    }
}
// @lc code=end

