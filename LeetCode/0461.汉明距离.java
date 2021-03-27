/*
 * @lc app=leetcode.cn id=461 lang=java
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
    public int hammingDistance(int x, int y) {
        int[] a = new int[32];
        int[] b = new int[32];
        int count1 = 0, count2 = 0, res = 0;
        while (x > 0) {
            a[count1++] = x % 2;
            x /= 2;
        }
        while (y > 0) {
            b[count2++] = y % 2;
            y /= 2;
        }
        for (int i = 0; i < Math.max(count1, count2); i++) {
            if (a[i] != b[i]) {
                res ++;
            }
        }
        return res;
    }
}
// @lc code=end

