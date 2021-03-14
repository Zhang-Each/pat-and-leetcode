/*
 * @lc app=leetcode.cn id=995 lang=java
 *
 * [995] K 连续位的最小翻转次数
 */

// @lc code=start
class Solution {
    public int minKBitFlips(int[] a, int k) {
        int res = 0;
        int[] count = new int[a.length];
        for (int i = 0; i < a.length; i ++) {
            if ((count[i] + a[i]) % 2 == 0) {
                res += 1;
                if (i + k > a.length) {
                    return -1;
                }
                for (int j = i; j < i + k; j++) {
                    count[j] += 1;
                }
            }
        }
        return res;
    }
}
// @lc code=end

