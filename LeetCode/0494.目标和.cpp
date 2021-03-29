/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0, target = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
        }
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        target = (sum + S) / 2;
        int *dp = new int [target + 1];
        for (int i = 0; i <= target; i ++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        // 找到n个数的和为一个定值的方法：动态规划
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = target; j >= nums[i]; j --) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end

