/*
 * @lc app=leetcode.cn id=397 lang=java
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
    public int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        } else {
            return Math.min(integerReplacement(n / 2 + 1), integerReplacement((n - 1) / 2)) + 2;
        }
    }
}
// @lc code=end

