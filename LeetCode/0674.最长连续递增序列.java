/*
 * @lc app=leetcode.cn id=674 lang=java
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }
        int res = 0, left = 0, right = 1;
        while (right < nums.length) {
            if (nums[right] <= nums[right - 1]) {
                res = res < right - left ? right - left : res;
                left = right;
            }
            right += 1;
        }
        res = res < right - left ? right - left : res;
        return res;
    }
}
// @lc code=end

