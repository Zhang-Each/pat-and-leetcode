/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            res += mp[sum - k];
            mp[sum] += 1;
        }
        return res;
    }
};
// @lc code=end

