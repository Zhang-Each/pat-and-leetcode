/*
 * @lc app=leetcode.cn id=1004 lang=java
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
/**
 * 经典滑动窗口的题目
 */
class Solution {
    public int longestOnes(int[] a, int k) {
        int res = 0, i = 0, j = 0, count = 0;
        while (j < a.length) {
            if (a[j] == 0) {
                count ++;
            }
            j ++;
            while (count > k) {
                if (a[i] == 0) {
                    count --;
                }
                i ++;
            }
            if (j - i > res) {
                res = j - i;
            }
        }
        return res;
    }
}
// @lc code=end

