/*
 * @lc app=leetcode.cn id=33 lang=java
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            if (target == nums[left]) {
                return left;
            } else if (target == nums[right]) {
                return right;
            }
            int mid = left + (right - left) / 2;
            // 将数组分成两个部分，其中一部分一定是有序的
            // 在有序的那一部分里面找，无序的那一部分继续拆，很经典的题型
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] > target) {
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
        return -1;
    }
}
// @lc code=end

