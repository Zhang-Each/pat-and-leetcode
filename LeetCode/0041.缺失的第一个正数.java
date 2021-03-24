/*
 * @lc app=leetcode.cn id=41 lang=java
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
    public int firstMissingPositive(int[] nums) {
        int[] d = new int[nums.length + 2];
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] <= nums.length + 1 && nums[i] >= 1) {
                d[nums[i]] = 1;
            }
        }
        for (int i = 1; i <= nums.length + 1; i ++) {
            if (d[i] == 0) {
                return i;
            }
        }
        return 0;
    }
}

// @lc code=end

