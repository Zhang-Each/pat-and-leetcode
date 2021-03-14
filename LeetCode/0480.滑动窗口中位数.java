/*
 * @lc app=leetcode.cn id=480 lang=java
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] res = new double[nums.length - k + 1];
        for (int i = 0; i < nums.length - k + 1; i++) {
            int[] temp = new int[k];
            System.arraycopy(nums, i, temp, 0, k);
            Arrays.sort(temp);
            if (k % 2 == 0) {
                res[i] = (1.0 * temp[k / 2 - 1] + 1.0 * temp[k / 2]) / 2;
            } else {
                res[i] = temp[k / 2];
            }
        }
        return res;
    }
}
// @lc code=end

