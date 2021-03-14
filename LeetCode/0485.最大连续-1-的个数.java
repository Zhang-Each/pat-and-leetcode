/*
 * @lc app=leetcode.cn id=485 lang=java
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxCount = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxCount = maxCount > count ? maxCount: count;
                count = 0;
            }
        }
        maxCount = maxCount > count ? maxCount: count;
        return maxCount;
    }
}
// @lc code=end

