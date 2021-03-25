/*
 * @lc app=leetcode.cn id=1539 lang=java
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
class Solution {
    public int findKthPositive(int[] arr, int k) {
        int[] nums = new int[arr.length + k + 2];
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < nums.length) {
                nums[arr[i]] = 1;
            }
        }
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == 0) {
                count += 1;
            }
            if (count == k) {
                return i;
            }
        }
        return 0;
    }
}
// @lc code=end

