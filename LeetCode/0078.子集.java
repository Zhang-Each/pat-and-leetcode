/*
 * @lc app=leetcode.cn id=78 lang=java
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    public List<List<Integer>> res = new ArrayList<>();
    public List<Integer> temp = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        travel(0, nums);
        return res;
    }

    private void travel(int index, int[] nums) {
        res.add(new ArrayList<Integer>(temp));
        if (temp.size() == nums.length) {
            return;
        }
        for (int i = index; i < nums.length; i ++) {
            temp.add(nums[i]);
            travel(i + 1, nums);
            temp.remove(temp.size() - 1);
        }
    }
}
// @lc code=end

