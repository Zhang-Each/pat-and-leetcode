/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
    // 经典滑动窗口
    public int minSubArrayLen(int target, int[] nums) {
        int res = nums.length + 1, sum = 0, i = 0;
        for (int j = 0; j < nums.length; j ++) {
            sum += nums[j];
            while (sum >= target) {
                res = Math.min(res, j - i + 1);
                sum -= nums[i ++];
            }
        }
        return res == nums.length + 1 ? 0 : res;
    }
}
// @lc code=end

