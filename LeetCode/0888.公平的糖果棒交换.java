/*
 * @lc app=leetcode.cn id=888 lang=java
 *
 * [888] 公平的糖果棒交换
 */

// @lc code=start
class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int[] res = new int[2];
        int sumA = 0, sumB = 0;
        for (int i = 0; i < A.length; i++) {
            sumA += A[i];
        }
        for (int j = 0; j < B.length; j++) {
            sumB += B[j];
        }
        int delta = (sumA - sumB) / 2;

        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                if (A[i] - B[j] == delta) {
                    res[0] = A[i];
                    res[1] = B[j];
                    return res;
                }
            }
        }
        return res;
    }
}
// @lc code=end

