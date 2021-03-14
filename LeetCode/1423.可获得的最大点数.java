/*
 * @lc app=leetcode.cn id=1423 lang=java
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int len = cardPoints.length - k, sum = 0, minSum = 0, total = 0;
        for (int i = 0; i < cardPoints.length; i++) {
            if (i < len) {
                sum += cardPoints[i];
            }
            total += cardPoints[i];
        }
        minSum = sum;
        for (int i = len; i < cardPoints.length; i++) {
            sum += cardPoints[i] - cardPoints[i - len];
            if (sum < minSum) {
                minSum = sum;
            }
        }
        return total - minSum;
    }
}
// @lc code=end

