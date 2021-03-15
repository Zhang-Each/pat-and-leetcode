/*
 * @lc app=leetcode.cn id=136 lang=java
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
    public int singleNumber(int[] nums) {
        int a = 0;
        for (int i = 0; i < nums.length; i++) {
            a = a ^ nums[i];
        }
        return a;
    }
}
// @lc code=end

