/*
 * @lc app=leetcode.cn id=665 lang=java
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
    public boolean checkPossibility(int[] nums) {
        if (nums.length <= 2) {
            return true;
        }
        boolean change = true;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                if (change) {
                    change = false;
                    if (i >= 2 && nums[i] < nums[i - 2]) {
                        nums[i] = nums[i - 1];
                    } else if (i >= 2) {
                        nums[i - 1] = nums[i - 2];
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
// @lc code=end

