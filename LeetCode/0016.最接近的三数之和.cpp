/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i=0; i<nums.size()-2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
                if(sum == target) {
                    return target;
                } else if(sum < target) {
                    j++;
                } else if(sum > target) {
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

