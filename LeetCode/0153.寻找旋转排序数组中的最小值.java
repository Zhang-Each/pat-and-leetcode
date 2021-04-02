/*
 * @lc app=leetcode.cn id=153 lang=java
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1, min = 99999999;
        while (left <= right) {
            if (nums[left] < min) {
                min = nums[left];
            }
            if (nums[right] < min) {
                min = nums[right];
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] < min) {
                min = nums[mid];
            }
            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return min;
    }
}
// @lc code=end

