/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int[] dp = new int[prices.length];
        int minp = prices[0];
        for (int i = 1; i < prices.length; i ++) {
            dp[i] = Math.max(dp[i - 1], prices[i] - minp);
            if (minp > prices[i]) {
                minp = prices[i];
            }
        }
        return dp[prices.length - 1];
    }
}
// @lc code=end

