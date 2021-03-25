/*
 * @lc app=leetcode.cn id=55 lang=java
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
    public boolean canJump2(int[] nums) {
        boolean[] dp = new boolean[nums.length];
        dp[0] = true;
        for (int i = 0; i < nums.length; i++) {
            if (i + nums[i] >= nums.length - 1 && dp[i]) {
                return true;
            }
            for (int j = 1; j <= nums[i]; j ++) {
                if (i + j == dp.length - 1 && dp[i]) {
                    return true;
                }
                if (i + j < dp.length) {
                    dp[i + j] = dp[i];
                }
            }
        }
        return dp[nums.length - 1];
    }

    public boolean canJump(int[] nums) {
        if (nums.length <= 1) {
            return true;
        }
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (i <= max) {
                max = Math.max(max, nums[i] + i);
            }
        }
        return max >= nums.length - 1;
    }
}
// @lc code=end

