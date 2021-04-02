/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int max = -1000000, sum = 0, res = 0;
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        if (max <= 0) {
            return max;
        }
        for (int i = 0; i < nums.length; i ++) {
            sum += nums[i];
            if (sum > 0) {
                res = Math.max(res, sum);
            } else {
                sum = 0;
            }
        }
        return res;
    }
}
// @lc code=end

