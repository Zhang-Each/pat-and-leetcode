/*
 * @lc app=leetcode.cn id=217 lang=java
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> res = new HashSet<>();
        for (int i = 0; i < nums.length; i ++) {
            res.add(nums[i]);
        }
        return res.size() == nums.length ? false : true;
    }
}
// @lc code=end

