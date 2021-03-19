/*
 * @lc app=leetcode.cn id=90 lang=java
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> temp = new ArrayList<>();
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        travel(0, nums);
        return res;
    }

    private void travel(int i, int[] nums) {
        res.add(new ArrayList<>(temp));
        if (temp.size() == nums.length) {
            return;
        }
        for (int j = i; j < nums.length; j ++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }
            temp.add(nums[j]);
            travel(j + 1, nums);
            temp.remove(temp.size() - 1);
        }
    }
}
// @lc code=end

