/*
 * @lc app=leetcode.cn id=300 lang=java
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
    // 垃圾做法很容易想到，这里抄一种题解里面见过的好解法
    public int lengthOfLIS(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }
        // res[i]代表了长度为i+1的递增子序列中最小的那个末尾值
        int[] res = new int[nums.length];
        int len = 0;
        for (int i = 0; i < nums.length; i ++) {
            // 在0-len-1里面找nums[i]的位置，返回的地方是一个负数，需要再处理
            int index = Arrays.binarySearch(res, 0, len, nums[i]);
            // System.out.println(index);
            index = index < 0 ? -index - 1 : index;
            res[index] = nums[i];
            if (index == len) {
                len ++;
            }
        }
        return len;
    }
}

// @lc code=end

