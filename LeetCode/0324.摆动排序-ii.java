/*
 * @lc app=leetcode.cn id=324 lang=java
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int[] res = new int[nums.length];
        int mid = (nums.length + 1) / 2 - 1, i = nums.length - 1;
        for (int j = 0; j < nums.length; j++) {
            if (j % 2 == 1) {
                res[j] = nums[i --];
            } else {
                res[j] = nums[mid --];
            }
        }
        for (int j = 0; j < nums.length; j ++) {
            nums[j] = res[j];
        }
    }
}
// @lc code=end

