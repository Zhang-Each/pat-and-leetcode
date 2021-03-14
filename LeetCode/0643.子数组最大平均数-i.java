/*
 * @lc app=leetcode.cn id=643 lang=java
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        if (nums.length == k) {
            return 1.0 * sum / k;
        }
        int temp = sum;
        for (int i = k; i < nums.length; i++) {
            temp += nums[i] - nums[i - k];
            if (temp > sum) {
                sum = temp;
            }
        }
        return 1.0 * sum / k;
    }
}
// @lc code=end

