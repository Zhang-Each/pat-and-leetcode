/*
 * @lc app=leetcode.cn id=189 lang=java
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        for (int i = 0; i < k; i ++) {
            int temp = nums[nums.length - 1];
            for (int j = nums.length - 1; j >= 1; j --) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
        }
    }
}
// @lc code=end

