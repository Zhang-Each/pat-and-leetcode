/*
 * @lc app=leetcode.cn id=561 lang=java
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution {
    /**
     * 这道题其实就是两个一组进行划分，求出其中最小值的和
     * 我们分析可以发现这n个数的和肯定不会超过总和的一半，并且在两两分组中总是最小的值
     * 那么为了获得更大的和，应该让大的跟大的一组，小的跟小的一组
     * 因此可以先对数组进行排序，然后两个一组进行求和就是最大的和
     */
    public int arrayPairSum(int[] nums) {
        int res = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i += 2) {
            res += nums[i];
        }
        return res;
    }
}
// @lc code=end

