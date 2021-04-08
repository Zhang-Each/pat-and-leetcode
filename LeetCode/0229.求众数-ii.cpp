/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */
#include<vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> cnt;
        vector<int> res;
        int target = nums.size() / 3;
        for (int i = 0; i < nums.size(); i ++) {
            if (cnt[nums[i]] <= target) {
                cnt[nums[i]] += 1;
            }
            if (cnt[nums[i]] > target) {
                res.push_back(nums[i]);
                cnt[nums[i]] = - nums.size();
            }
        }
        return res;
    }
};
// @lc code=end

