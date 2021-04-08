/*
 * @lc app=leetcode.cn id=238 lang=java
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        Arrays.fill(res, 0, nums.length, 1);
        int left = 1, right = 1;
        for (int i = 0; i < res.length; i ++) {
            res[i] *= left;
            left *= nums[i];
            res[nums.length - 1 - i] *= right;
            right *= nums[nums.length - 1 - i];
        }
        return res;
    }
}
// @lc code=end

