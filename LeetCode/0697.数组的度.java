/*
 * @lc app=leetcode.cn id=697 lang=java
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
    public int findShortestSubArray(int[] nums) {
        int len = nums.length, maxCount = 0, minWindow = 0;
        Map<Integer, int[]> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            int[] pair = map.get(nums[i]);
            if (pair == null) {
                pair = new int[]{i, 1};
                map.put(nums[i], pair);
            } else {
                pair[1]++;
            }
            if (pair[1] > maxCount) {
                maxCount = pair[1];
                minWindow = i - pair[0] + 1;
            } else if (pair[1] == maxCount) {
                minWindow = Math.min(minWindow, i - pair[0] + 1);
            }
        }
        return minWindow; 
    }
}
// @lc code=end

