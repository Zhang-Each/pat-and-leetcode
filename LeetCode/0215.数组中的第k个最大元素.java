/*
 * @lc app=leetcode.cn id=215 lang=java
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Queue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i ++) {
            q.offer(nums[i]);
        }
        int target = nums.length - k;
        while (target > 0) {
            target --;
            q.poll();
        }
        return q.poll();
    }
}
// @lc code=end

