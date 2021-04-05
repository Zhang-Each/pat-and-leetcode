/*
 * @lc app=leetcode.cn id=81 lang=java
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
    public boolean search(int[] nums, int target) {
        if (nums.length == 1) {
            return nums[0] == target;
        }
        int left = 0, right = nums.length - 1;
        while (left < right) {
            if (target == nums[left] || target == nums[right]) {
                return true;
            }
            while (left < right && nums[left] == nums[left + 1]) {
                left ++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
                right --;
            }
            if (left > right) {
                return false;
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target < nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[mid] > target && target > nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
}


// @lc code=end

