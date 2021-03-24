/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
        for (int i = 1; i < nums.length; i ++) {
            dp[i] = nums.length + 1;
        }
        for (int i = 0; i < nums.length; i ++) {
            for (int j = 1; j <= nums[i]; j ++) {
                if (i + j < nums.length && dp[i + j] > dp[i] + 1) {
                    dp[i + j] = dp[i] + 1;
                }
            }
        }
        return dp[nums.length - 1];
    }
}
// @lc code=end

